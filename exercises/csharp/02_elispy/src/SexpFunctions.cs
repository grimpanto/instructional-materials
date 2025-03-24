// @copyright 2018 Günter Kolousek

namespace ko.elispy {
  using System;
  using System.Collections.Generic;

  public abstract class SexpFunction {
      protected string name;

      public SexpFunction(string name) : base() {
          this.name = name;
      }

      public abstract Sexp call(List<Sexp> args, Context ctx);

      public override string ToString() {
          return name;
      }
  }

  public abstract class BuiltinSexpFunction : SexpFunction {
      public BuiltinSexpFunction(string name) : base(name) {}
  }

  public class AddSexpFunction : BuiltinSexpFunction {
      public AddSexpFunction(string name) : base(name) {}
      public override Sexp call(List<Sexp> args, Context ctx) {
          int res=0;
          foreach (var sexp in args) {
              res += (int)(sexp.eval(ctx));
          }
          return res;
      }
  }

  public class SubSexpFunction : BuiltinSexpFunction {
      public SubSexpFunction(string name) : base(name) {}
      public override Sexp call(List<Sexp> args, Context ctx) {
          if (args.Count == 0)
              return 0;
          if (args.Count == 1)
              return -(int)args[0].eval(ctx);
          int res=(int)args[0].eval(ctx);
          for (int i=1; i < args.Count; ++i) {
              res -= (int)(args[i].eval(ctx));
          }
          return res;
      }
  }

  public class MulSexpFunction : BuiltinSexpFunction {
      public MulSexpFunction(string name) : base(name) {}
      public override Sexp call(List<Sexp> args, Context ctx) {
          int res=1;
          foreach (var sexp in args) {
              res *= (int)(sexp.eval(ctx));
          }
          return res;
      }
  }

  public class DivSexpFunction : BuiltinSexpFunction {
      public DivSexpFunction(string name) : base(name) {}
      public override Sexp call(List<Sexp> args, Context ctx) {
          if (args.Count == 0)
              throw new ArgumentException("/ called with 0 arguments");
          if (args.Count == 1)
              return 1 / (int)(args[0].eval(ctx));
          int res = (int)(args[0].eval(ctx));
          for (int i=1; i < args.Count; ++i) {
              res /= (int)(args[i].eval(ctx));
          }
          return res;
      }
  }

  public class LessThanSexpFunction : BuiltinSexpFunction {
      public LessThanSexpFunction(string name) : base(name) {}
      public override Sexp call(List<Sexp> args, Context ctx) {
          if (args.Count != 2)
              throw new ArgumentException($"Function {name} called with {args.Count} arguments (2 needed)");
          int a=(int)(args[0].eval(ctx));
          int b=(int)(args[1].eval(ctx));
          return (a < b) ?
            (Sexp)ctx.symtab["t"] : (Sexp)ctx.symtab["nil"];
      }
  }

  public class LessThanOrEqualSexpFunction : BuiltinSexpFunction {
      public LessThanOrEqualSexpFunction(string name) : base(name) {}
      public override Sexp call(List<Sexp> args, Context ctx) {
          if (args.Count != 2)
              throw new ArgumentException($"Function {name} called with {args.Count} arguments (2 needed)");
          int a=(int)(args[0].eval(ctx));
          int b=(int)(args[1].eval(ctx));
          return (a <= b) ?
            (Sexp)ctx.symtab["t"] : (Sexp)ctx.symtab["nil"];
      }
  }

  public class EqualsSexpFunction : BuiltinSexpFunction {
      public EqualsSexpFunction(string name) : base(name) {}
      public override Sexp call(List<Sexp> args, Context ctx) {
          if (args.Count != 2)
              throw new ArgumentException($"Function {name} called with {args.Count} arguments (2 needed)");
          int a=(int)(args[0].eval(ctx));
          int b=(int)(args[1].eval(ctx));
          return (a == b) ?
            (Sexp)ctx.symtab["t"] : (Sexp)ctx.symtab["nil"];
      }
  }

  public class GreaterThanOrEqualSexpFunction : BuiltinSexpFunction {
      public GreaterThanOrEqualSexpFunction(string name) : base(name) {}
      public override Sexp call(List<Sexp> args, Context ctx) {
          if (args.Count != 2)
              throw new InterpreterException($"Function {name} called with {args.Count} arguments (2 needed)");
          int a=(int)(args[0].eval(ctx));
          int b=(int)(args[1].eval(ctx));
          return (a >= b) ?
            (Sexp)ctx.symtab["t"] : (Sexp)ctx.symtab["nil"];
      }
  }

  public class GreaterThanSexpFunction : BuiltinSexpFunction {
      public GreaterThanSexpFunction(string name) : base(name) {}
      public override Sexp call(List<Sexp> args, Context ctx) {
          if (args.Count != 2)
              throw new InterpreterException($"Function {name} called with {args.Count} arguments (2 needed)");
          int a=(int)(args[0].eval(ctx));
          int b=(int)(args[1].eval(ctx));
          return (a > b) ?
            (Sexp)ctx.symtab["t"] : (Sexp)ctx.symtab["nil"];
      }
  }

  public class FirstSexpFunction : BuiltinSexpFunction {
      public FirstSexpFunction(string name) : base(name) {}
      public override Sexp call(List<Sexp> args, Context ctx) {
          if (args.Count != 1)
              throw new ArgumentException($"first could not be called with {args.Count} arguments (exactly one expected)");

          //Console.WriteLine(args[0].eval(ctx));
          SexpList arg_as_sexplist=args[0].eval(ctx) as SexpList;
          //Console.WriteLine(arg_as_sexplist);
          if (arg_as_sexplist == null)
              throw new ArgumentException($"first could not be called with an argument that's not a list");

          List<Sexp> terms=arg_as_sexplist.terms;
          if (terms.Count > 0) {
              return terms[0];
          } else
              return (Sexp)ctx.symtab["nil"];
      }
  }

  public class RestSexpFunction : BuiltinSexpFunction {
      public RestSexpFunction(string name) : base(name) {}
      public override Sexp call(List<Sexp> args, Context ctx) {
          if (args.Count != 1)
              throw new ArgumentException($"rest could not be called with {args.Count} arguments (exactly one expected)");

          SexpList arg_as_sexplist=args[0].eval(ctx) as SexpList;
          if (arg_as_sexplist == null)
              throw new ArgumentException($"rest could not be called with an argument that's not a list");

          List<Sexp> terms=arg_as_sexplist.terms;
          if (terms.Count > 0) {
              SexpList res=new SexpList();
              res.terms.AddRange(terms.GetRange(1, terms.Count - 1));
              return res;
          } else
              return (Sexp)ctx.symtab["nil"];
      }
  }

  public class ConsSexpFunction : BuiltinSexpFunction {
      public ConsSexpFunction(string name) : base(name) {}
      public override Sexp call(List<Sexp> args, Context ctx) {
          if (args.Count != 2)
              throw new ArgumentException($"cons could not be called with {args.Count} arguments (exactly two expected)");

          Sexp arg1=args[0].eval(ctx);

          SexpList arg2=args[1].eval(ctx) as SexpList;
          if (arg2 == null)
              throw new ArgumentException($"cons could not be called with a second argument that's not a list");

          SexpList res=new SexpList(arg2.terms);
          res.terms.Insert(0, arg1);
          return res;
      }
  }

  public class EqualSexpFunction : BuiltinSexpFunction {
      public EqualSexpFunction(string name) : base(name) {}
      public override Sexp call(List<Sexp> args, Context ctx) {
          if (args.Count != 2)
              throw new ArgumentException($"equal could not be called with {args.Count} arguments (exactly two expected)");

          Sexp arg1=args[0].eval(ctx);
          Sexp arg2=args[1].eval(ctx);

          return (arg1 == arg2) ? ctx.symtab["t"] : ctx.symtab["nil"];
      }
  }

  public class SetqSexpFunction : BuiltinSexpFunction {
      public SetqSexpFunction(string name) : base(name) {}
      public override Sexp call(List<Sexp> args, Context ctx) {
          if (args.Count != 2)
              throw new ArgumentException($"setq could not be called with {args.Count} arguments (exactly two expected)");

          SexpSymbol arg_as_sexpsymbol=args[0] as SexpSymbol;
          if (arg_as_sexpsymbol == null)
              throw new ArgumentException($"setq could not be called with first argument that's not a symbol");

          Sexp res = args[1].eval(ctx);
          ctx.symtab[arg_as_sexpsymbol.value] = res;
          return res;
      }
  }

  public class NullSexpFunction : BuiltinSexpFunction {
      public NullSexpFunction(string name) : base(name) {}
      public override Sexp call(List<Sexp> args, Context ctx) {
          if (args.Count != 1)
              throw new ArgumentException($"null could not be called with {args.Count} arguments (exactly one expected)");

          Sexp arg1=args[0].eval(ctx);
          if (arg1.is_null())
              return ctx.symtab["t"];
          else
              return ctx.symtab["nil"];
      }
  }


  public class IfSexpFunction : BuiltinSexpFunction {
      public IfSexpFunction(string name) : base(name) {}
      public override Sexp call(List<Sexp> args, Context ctx) {
          if (args.Count != 2 && args.Count != 3)
              throw new ArgumentException($"if could not be called with {args.Count} arguments (two or three expected)");

          Sexp arg1=args[0].eval(ctx);
          Sexp arg2=args[1];
          Sexp arg3=null;
          if (args.Count == 3)
              arg3=args[2];

          Sexp res;

          if ((bool)arg1) {
              res = arg2.eval(ctx);
          } else {
              if (arg3 != null)
                  res = arg3.eval(ctx);
              else
                  res = ctx.symtab["nil"];
          }

          return res;
      }
  }

  public class PrincSexpFunction : BuiltinSexpFunction {
      public PrincSexpFunction(string name) : base(name) {}
      public override Sexp call(List<Sexp> args, Context ctx) {
          if (args.Count != 1)
              throw new ArgumentException($"princ could not be called with {args.Count} arguments (exactly 1 expected)");

          Sexp res=args[0].eval(ctx);
          if (res is SexpString)
              System.Console.WriteLine(((SexpString)res).value);
          else
              System.Console.WriteLine(res);
          return res;
      }
  }

  public class PrognSexpFunction : BuiltinSexpFunction {
      public PrognSexpFunction(string name) : base(name) {}
      public override Sexp call(List<Sexp> args, Context ctx) {
          Sexp res=ctx.symtab["nil"];
          foreach (var sexp in args) {
              res = sexp.eval(ctx);
          }
          return res;
      }
  }

  public class WhileSexpFunction : BuiltinSexpFunction {
      public WhileSexpFunction(string name) : base(name) {}
      public override Sexp call(List<Sexp> args, Context ctx) {
          if (args.Count <= 1)
              throw new ArgumentException($"while could not be called with {args.Count} arguments (at least 2 expected)");

          Sexp res;
          while ((bool)(res = args[0].eval(ctx))) {
              for (int i=1; i < args.Count; ++i) {
                  Sexp tmp=args[i].eval(ctx);
              }
          }
          return res;
      }
  }

  public class ShellCommandSexpFunction : BuiltinSexpFunction {
      public ShellCommandSexpFunction(string name) : base(name) {}
      public override Sexp call(List<Sexp> args, Context ctx) {
          if (args.Count != 1)
              throw new ArgumentException($"shell-command could not be called with {args.Count} arguments (exactly one expected)");

          SexpString cmd=args[0].eval(ctx) as SexpString;
          if (cmd == null)
              throw new ArgumentException($"shell expects a string argument");

          try {
              return new SexpString(Utility.shell_exec(cmd.value));
          } catch (InvalidOperationException e) {
              throw new ArgumentException($"{e}");
          }
      }
  }

  public class NotSexpFunction : BuiltinSexpFunction {
      public NotSexpFunction(string name) : base(name) {}
      public override Sexp call(List<Sexp> args, Context ctx) {
          if (args.Count != 1)
              throw new ArgumentException($"not could not be called with {args.Count} arguments (exactly one expected)");

          Sexp arg=args[0].eval(ctx);

          if (arg.is_null())
              return ctx.symtab["t"];
          else
              return ctx.symtab["nil"];
      }
  }

  public class AndSexpFunction : BuiltinSexpFunction {
      public AndSexpFunction(string name) : base(name) {}
      public override Sexp call(List<Sexp> args, Context ctx) {
          Sexp res=ctx.symtab["t"];
          foreach (var sexp in args) {
              res = sexp.eval(ctx);
              if (res.is_null())
                  return ctx.symtab["nil"];
          }
          return res;
      }
  }

  public class OrSexpFunction : BuiltinSexpFunction {
      public OrSexpFunction(string name) : base(name) {}
      public override Sexp call(List<Sexp> args, Context ctx) {
          Sexp res=ctx.symtab["nil"];
          foreach (var sexp in args) {
              res = sexp.eval(ctx);
              if (!res.is_null())
                  return res;
          }
          return res;
      }
  }
}
