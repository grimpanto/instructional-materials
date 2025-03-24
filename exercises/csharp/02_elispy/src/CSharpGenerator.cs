// @copyright 2018 Günter Kolousek

namespace ko.elispy {
  using System;
  using System.Text;
  using System.Collections.Generic;
  using System.Linq;
  using ko.lexer;

  public interface CodeGenerator {
      void visit(SexpSymbol sexpsym);
      void visit(SexpString sexpstr);
      void visit(SexpInteger sexpint);
      void visit(SexpList sexplst);
  }


  class CSharpGenerator : CodeGenerator {
      StringBuilder code;
      int indent=8;  // start indentation inside Main
      Context ctx=new Context();

      public CSharpGenerator(StringBuilder code) {
          this.code = code;
      }

      public void start() {
          code.AppendLine("using System;");
          code.AppendLine("using System.Collections.Generic;");
          code.AppendLine("using ko.elispy;");
          code.AppendLine();
          code.AppendLine("class Program {");
          code.AppendLine("    public static void Main() {");
          code.AppendLine("        var ctx = new Context();");
      }

      public void end() {
          code.Append("     }\n");
          code.Append("}\n");
      }

      public void print_indentation() {
          code.Append(String.Concat(Enumerable.Repeat(" ", indent)));
      }

      public void visit(SexpSymbol sexpsym) {
          code.AppendFormat("ctx.symtab[\"{0}\"]", sexpsym.ToString());
      }


      public void visit(SexpString sexpstr) {
          code.AppendFormat("new SexpString({0})", sexpstr.ToString());
      }


      public void visit(SexpInteger sexpint) {
          code.AppendFormat("new SexpInteger({0})", sexpint.ToString());
      }


      public void visit(SexpList sexplst) {
          if (sexplst.is_quoted) {
              code.AppendFormat("new SexpList(new List<Sexp>{{{0}}}, new Position({1}, {2}, {3}), true)",
                string.Join(", ", sexplst.terms),
                sexplst.position.GetValueOrDefault().idx,
                sexplst.position.GetValueOrDefault().line,
                sexplst.position.GetValueOrDefault().column);
              return;
          }

          if (sexplst.terms.Count == 0) {
              code.Append("ctx.symtab[\"nil\"]");
              return;
          }

          if (!(sexplst.terms[0] is SexpSymbol))
              throw new TranspilerException(
                $"First item must be a symbol, but got \"{sexplst.terms[0]}\" at {sexplst.position}");

          try {
              //code.AppendFormat("{0} ", ctx.functab[((SexpSymbol)sexplst.terms[0]).value]);
              gen_code(ctx.functab[((SexpSymbol)(sexplst.terms[0])).value],
                sexplst.terms.GetRange(1, sexplst.terms.Count - 1));

          } catch (Exception e) {
              throw new TranspilerException(
                $"code for {sexplst} could not be generated at {sexplst.position}", e);
          }
      }


      void gen_code(AddSexpFunction func, List<Sexp> args) {
          code.Append("new SexpInteger(0");
          foreach (var sexp in args) {
              code.Append(" + (int)((");
              sexp.accept(this);
              code.Append(").eval(ctx))");
          }
          code.Append(")");
      }


      void gen_code(SubSexpFunction func, List<Sexp> args) {
          code.Append("new SexpInteger(");
          if (args.Count == 0) {
              code.Append("0");
          } else if (args.Count == 1) {
              code.Append("-(int)((");
              args[0].accept(this);
              code.Append(").eval(ctx))");
          } else {
              code.AppendFormat("(int)((");
              args[0].accept(this);
              code.Append(").eval(ctx))");
              for (int i=1; i < args.Count; ++i) {
                  code.Append(" - (int)((");
                  args[i].accept(this);
                  code.Append(").eval(ctx))");
              }
          }
          code.Append(")");
      }


      void gen_code(MulSexpFunction func, List<Sexp> args) {
          code.Append("new SexpInteger(1");
          foreach (var sexp in args) {
              code.Append(" * (int)((");
              sexp.accept(this);
              code.Append(").eval(ctx))");
          }
          code.Append(")");
      }


      // ok!
      void gen_code(LessThanSexpFunction func, List<Sexp> args) {
          code.Append("(((int)(");
          args[0].accept(this);
          code.Append(").eval(ctx))");

          code.Append(" < ");

          code.Append("((int)(");
          args[1].accept(this);
          code.Append(").eval(ctx))");

          code.Append(") ? (Sexp)ctx.symtab[\"t\"] : (Sexp)ctx.symtab[\"nil\"]");
      }


      void gen_code(LessThanOrEqualSexpFunction func, List<Sexp> args) {
          code.Append("(int)((");
          args[0].accept(this);
          code.Append(").eval(ctx)) <= (int)((");
          args[1].accept(this);
          code.Append(").eval(ctx))");
      }


      void gen_code(EqualsSexpFunction func, List<Sexp> args) {
          code.Append("(int)((");
          args[0].accept(this);
          code.Append(").eval(ctx)) == (int)((");
          args[1].accept(this);
          code.Append(").eval(ctx))");
      }


      void gen_code(GreaterThanSexpFunction func, List<Sexp> args) {
          code.Append("(int)((");
          args[0].accept(this);
          code.Append(").eval(ctx)) > (int)((");
          args[1].accept(this);
          code.Append(").eval(ctx))");
      }


      void gen_code(GreaterThanOrEqualSexpFunction func, List<Sexp> args) {
          code.Append("(int)((");
          args[0].accept(this);
          code.Append(").eval(ctx)) >= (int)((");
          args[1].accept(this);
          code.Append(").eval(ctx))");
      }


      void gen_code(SetqSexpFunction func, List<Sexp> args) {
          code.AppendFormat("ctx.symtab[\"{0}\"] = (", args[0]);
          args[1].accept(this);
          code.Append(").eval(ctx)");
      }


      void gen_code(WhileSexpFunction func, List<Sexp> args) {
          code.Append("while ((bool)(");
          args[0].accept(this);
          code.Append(".eval(ctx))) {\n");
          indent += 4;
          for (int i=1; i < args.Count; ++i) {
              print_indentation();
              code.Append("(");
              args[i].accept(this);
              code.Append(").eval(ctx)");
              code.Append(";\n");
          }
          indent -= 4;
          print_indentation();
          code.Append("}");
      }


      void gen_code(PrincSexpFunction func, List<Sexp> args) {
          code.Append("Console.WriteLine((");
          args[0].accept(this);
          code.Append(").eval(ctx))");
      }
  }
}
