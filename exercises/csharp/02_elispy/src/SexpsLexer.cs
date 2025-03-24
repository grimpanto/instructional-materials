// @copyright 2018 Günter Kolousek

namespace ko.elispy {
  using System;

  using lexer;

  public static class Tokens {
      public const string LPAREN="LPAREN";
      public const string RPAREN="RPAREN";
      public const string SYMBOL="SYMBOL";
      public const string STRING="STRING";
      public const string INTEGER="INTEGER";
      public const string SPACE="SPACE";
      public const string QUOTE="QUOTE";
  }

  public class SexpsLexer : Lexer {
      public SexpsLexer() {
          add_definition(new Definition(Tokens.LPAREN, @"\("));
          add_definition(new Definition(Tokens.RPAREN, @"\)"));
          add_definition(new Definition(Tokens.QUOTE, @"'"));
          add_definition(new Definition(Tokens.INTEGER, @"[+-]?\d+"));
          add_definition(new Definition(Tokens.SYMBOL, @"([\w-[0-9]]\w*)|<=|==|>=|[<>+/*-]"));
          add_definition(new Definition(Tokens.STRING, @"""[^""]*"""));
          add_definition(new Definition(Tokens.SPACE, @"\s+", true));
      }

      public void test() {
          var tokens = tokenize("(+ 1 2 \"abc def\"");
          foreach (var token in tokens)
              Console.WriteLine(token);

          tokens = tokenize("'(+ 1 2)");
          foreach (var token in tokens)
              Console.WriteLine(token);

          tokens = tokenize("(name _n_ame _ < <= == > >=)");
          foreach (var token in tokens)
              Console.WriteLine(token);

          tokens = tokenize("'(+ 1 2)");
          foreach (var token in tokens)
              Console.WriteLine(token);

          tokens = tokenize("(- 1 \n 2 \r\n 3)");
          foreach (var token in tokens)
              Console.WriteLine(token);

          tokens = tokenize("(+ 1 \n  3)");
          foreach (var token in tokens)
              Console.WriteLine(token);

          tokens = tokenize("(+ 1 \r\n  3)");
          foreach (var token in tokens)
              Console.WriteLine(token);

          tokens = tokenize("1.5");
          try {
              foreach (var token in tokens)
                  Console.WriteLine(token);
          } catch (LexerException e) {
              Console.WriteLine(e.Message);
          }
      }
  }
}
