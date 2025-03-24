// @copyright 2018 Günter Kolousek

namespace ko.lexer {
  using System;

  class LexerException : Exception {
      public LexerException() {}
      public LexerException(string msg) : base(msg) {}
      public LexerException(string msg, Exception inner) : base(msg, inner) {}
  }
}
