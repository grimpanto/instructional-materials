// @copyright 2018 Günter Kolousek

using System;
using System.Collections.Generic;

namespace ko.lexer {
  public interface ILexer {
      void add_definition(Definition def);
      IEnumerable<Token> tokenize(string source);
  }
}
