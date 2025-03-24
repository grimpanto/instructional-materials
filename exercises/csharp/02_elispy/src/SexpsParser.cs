// @copyright 2018 Günter Kolousek

namespace ko.elispy {
  using System;
  using System.Collections.Generic;
  using System.Text.RegularExpressions;

  using lexer;

  /*
    program = {sexp}
    sexp = atom | list | ["'"] sexp
    list = "(", { sexp }, ")"
    atom = STRING | INTEGER | SYMBOL
  */

  class SexpsParser : IParser {
      private ILexer lexer;
      private IEnumerator<Token> tokens;
      private Token curr;
      private bool curr_is_valid;
      private Context ctx;


      public SexpsParser(ILexer lexer, Context ctx) {
          this.lexer = lexer;
          this.ctx = ctx;
      }


      public List<Sexp> parse(string source) {
          tokens=lexer.tokenize(source).GetEnumerator();
          return program();
      }


      private List<Sexp> program() {
          var res=new List<Sexp>();
          curr_is_valid = tokens.MoveNext();
          while (curr_is_valid) {
              curr=tokens.Current;
              res.Add(sexp());
          }
          return res;
      }


      private Sexp sexp() {
          bool is_quoted=false;
          Sexp res;
          if (curr.type == Tokens.QUOTE) {
              curr_is_valid = tokens.MoveNext();
              curr = tokens.Current;
              is_quoted = true;
          }

          if (curr.type.In(Tokens.SYMBOL, Tokens.STRING, Tokens.INTEGER)) {
              res = atom();
          } else if (curr.type == Tokens.LPAREN) {
              res = list();
          } else
              throw new ParserException($"Neither '(' nor an atom found at {curr.position}");

          if (is_quoted)
              res.is_quoted = true;
          return res;
      }


      private SexpAtom atom() {
          SexpAtom res;
          switch (curr.type) {
            case Tokens.SYMBOL:
              //Console.Write($"{curr.value} ");
              res = new SexpSymbol(curr.value, curr.position);
              break;
            case Tokens.STRING:
              //Console.Write($"{curr.value} ");
              res = new SexpString(curr.value, curr.position);
              break;
            case Tokens.INTEGER:
              //Console.Write($"{curr.value} ");
              res = new SexpInteger(int.Parse(curr.value), curr.position);
              break;
            default:
              throw new ParserException($"Atom expected but {curr.type} got at {curr.position}");
          }
          curr_is_valid = tokens.MoveNext();
          curr = tokens.Current;
          return res;
      }


      private SexpList list() {
          SexpList res=new SexpList(curr.position);
          //Console.Write("(");

          if (!(curr_is_valid = tokens.MoveNext()))
              throw new ParserException($"Opening '(' but EOF at {curr.position}");
          curr = tokens.Current;

          while (curr_is_valid && curr.type != Tokens.RPAREN) {
              res.add_term(sexp());
          }

          if (!curr_is_valid || curr.type != Tokens.RPAREN)
              throw new ParserException($"Missing ')' or EOF at {curr.position}");

          curr_is_valid = tokens.MoveNext();
          curr = tokens.Current;
          return res;
      }


      public void test() {
          List<Sexp> slist=parse(@"(+ 1 name ""abc def"")");
          Console.WriteLine(slist[0].ToString());

          slist=parse(@"'()");
          Console.WriteLine(slist[0].ToString());

          slist=parse(@"'nil");
          Console.WriteLine(slist[0].ToString());

          slist=parse(@"'(+ 1 2)");
          Console.WriteLine(slist[0].ToString());

          slist=parse(@"'(  +  1   2 )");
          Console.WriteLine(slist[0].ToString());

          try {
              parse(@"(+ 1 2");
          } catch (Exception e) {
              Console.WriteLine("(+ 1 2\t\t" + e.Message);
          }

          try {
              parse(@"(.+ 1 2 )))");
          } catch (Exception e) {
              Console.WriteLine("(.+ 1 2 )))\t" + e.Message);
          }

          try {
              parse(@"(");
          } catch (Exception e) {
              Console.WriteLine("(\t\t" + e.Message);
          }
      }
  }
}
