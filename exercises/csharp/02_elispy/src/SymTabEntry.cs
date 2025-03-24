// @copyright 2018 Günter Kolousek

namespace ko.elispy {

  using SymTab=System.Collections.Generic.Dictionary<string, Sexp>;
  using FuncTab=System.Collections.Generic.Dictionary<string, SexpFunction>;


  public static class Extensions {
      public static void initialize(this SymTab symtab) {
          symtab["t"] = new SexpSymbol("t");
          symtab["nil"] = new SexpSymbol("nil");
      }

      public static void initialize(this FuncTab functab) {
          functab["+"] = new AddSexpFunction("+");
          functab["<"] = new LessThanSexpFunction("<");
          functab["first"] = new FirstSexpFunction("first");
          functab["rest"] = new RestSexpFunction("rest");
      }
  }
}
