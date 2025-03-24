// @copyright 2018 Günter Kolousek

namespace ko.elispy {

  using SymTab=System.Collections.Generic.Dictionary<string, Sexp>;
  using FuncTab=System.Collections.Generic.Dictionary<string, SexpFunction>;

  using System.Collections.Generic;

  public class Context {
      public SymTab symtab=new SymTab();
      public FuncTab functab=new FuncTab();

      public Context() {
          symtab["t"] = new SexpSymbol("t");
          //symtab["nil"] = new SexpSymbol("nil");
          symtab["nil"] = new SexpList(new List<Sexp>());

          functab["+"] = new AddSexpFunction("+");
          functab["-"] = new SubSexpFunction("-");
          functab["*"] = new MulSexpFunction("*");
          functab["/"] = new DivSexpFunction("/");

          functab["<"] = new LessThanSexpFunction("<");
          functab["<="] = new LessThanOrEqualSexpFunction("<=");
          functab["="] = new EqualsSexpFunction("=");
          functab[">"] = new GreaterThanSexpFunction(">");
          functab[">="] = new GreaterThanOrEqualSexpFunction(">=");

          functab["first"] = new FirstSexpFunction("first");
          functab["rest"] = new RestSexpFunction("rest");
          functab["cons"] = new ConsSexpFunction("cons");
          functab["equal"] = new EqualSexpFunction("equal");
          functab["setq"] = new SetqSexpFunction("setq");
          functab["null"] = new NullSexpFunction("null");
          functab["if"] = new IfSexpFunction("setq");
          functab["progn"] = new PrognSexpFunction("progn");
          functab["princ"] = new PrincSexpFunction("princ");
          functab["while"] = new WhileSexpFunction("while");
          functab["shell"] = new ShellCommandSexpFunction("shell");
          functab["not"] = new NotSexpFunction("not");
          functab["and"] = new AndSexpFunction("and");
          functab["or"] = new OrSexpFunction("or");
      }
  }
}
