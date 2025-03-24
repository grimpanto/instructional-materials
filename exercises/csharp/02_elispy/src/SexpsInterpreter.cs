// @copyright 2018 Günter Kolousek

namespace ko.elispy {
  using System;
  using System.Collections.Generic;
  using System.Linq;

  class SexpsInterpreter {
      private SexpsParser parser;

      public SexpsInterpreter(SexpsParser parser) {
          this.parser = parser;
      }

      public void repl() {
          Context ctx=new Context();
          while (true) {
              Console.Write("elispy> ");
              //Console.SetCursorPosition(8, Console.CursorTop);
              string input=Console.ReadLine();

              if (input == null)
                  break;

              input = input.Trim();
              input = new string(input.Where(c => !char.IsControl(c)).ToArray());

              if (input == "")
                  continue;

              try {
                  List<Sexp> lst=parser.parse(input);
                  for (int i=0; i < lst.Count; ++i) {
                      Sexp res=lst[i].eval(ctx);
                      if (i == lst.Count - 1)
                          Console.WriteLine(res);
                  }
              } catch (Exception e) {
                  Console.WriteLine(e.get_full_message());
              }
          }
      }

      public void test() {
          Console.WriteLine(parser.parse("1")[0].eval());
          Console.WriteLine(parser.parse("\"abc\"")[0].eval());
          Console.WriteLine(parser.parse("'1")[0].eval());
          Console.WriteLine(parser.parse("'\"abc\"")[0].eval());
          Console.WriteLine(parser.parse("'a")[0].eval());

          try {
              Console.WriteLine(parser.parse("a")[0].eval());
          } catch (InterpreterException e) {
              var a="a";
              Console.WriteLine($"{a,-15} {e.Message}");
          }

          Context ctx=new Context();
          ctx.symtab["a"] = new SexpInteger(1);
          foreach (var x in ctx.symtab)
              Console.WriteLine(x);

          Console.WriteLine(parser.parse("a")[0].eval(ctx));

          Console.WriteLine(parser.parse("'(1 2 3)")[0].eval());

          Console.WriteLine(parser.parse("()")[0].eval(ctx));

          try {
              parser.parse("(1 2 3)")[0].eval(ctx);
          } catch (InterpreterException e) {
              var v="(1 2 3)";
              Console.WriteLine($"{v,-15} {e.Message}");
          }

          Console.WriteLine(parser.parse(@"(+)")[0].eval(ctx));
          Console.WriteLine(parser.parse(@"(+ 1)")[0].eval(ctx));
          Console.WriteLine(parser.parse(@"(+ 1 2)")[0].eval(ctx));
          Console.WriteLine(parser.parse(@"(+ 1 2 3)")[0].eval(ctx));
          Console.WriteLine(parser.parse(@"(+ 1 (+ 2 3))")[0].eval(ctx));

          try {
              Console.WriteLine(parser.parse(@"(+ 1 ""a"")")[0].eval(ctx));
          } catch (InterpreterException e) {
              var v=@"(+ 1 ""a"")";
              Console.WriteLine($"{v,-15} {e.Message}");
          }

          Console.WriteLine(parser.parse(@"(-)")[0].eval(ctx));
          Console.WriteLine(parser.parse(@"(- 1)")[0].eval(ctx));
          Console.WriteLine(parser.parse(@"(- 1 2)")[0].eval(ctx));
          Console.WriteLine(parser.parse(@"(- 1 2 3)")[0].eval(ctx));

          Console.WriteLine(parser.parse(@"(*)")[0].eval(ctx));
          Console.WriteLine(parser.parse(@"(* 1)")[0].eval(ctx));
          Console.WriteLine(parser.parse(@"(* 1 2)")[0].eval(ctx));
          Console.WriteLine(parser.parse(@"(* 1 2 3)")[0].eval(ctx));

          try {
              Console.WriteLine(parser.parse(@"(/)")[0].eval(ctx));
          } catch (InterpreterException e) {
              var v=@"(-)";
              Console.WriteLine($"{v,-15} {e.Message}");
          }

          Console.WriteLine(parser.parse(@"(/ 1)")[0].eval(ctx));
          Console.WriteLine(parser.parse(@"(/ 2 1)")[0].eval(ctx));
          Console.WriteLine(parser.parse(@"(/ 3 2 1)")[0].eval(ctx));

          Console.WriteLine(parser.parse("(< 1 2)")[0].eval(ctx));
          Console.WriteLine(parser.parse("(first '(1 2 3))")[0].eval(ctx));
          Console.WriteLine(parser.parse("(rest '(1 2 3))")[0].eval(ctx));


      }
  }
}
