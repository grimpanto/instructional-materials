// @copyright 2018 Günter Kolousek

namespace ko.elispy {
  using System;

  class ParserException : Exception {
      public ParserException() {}
      public ParserException(string msg) : base(msg) {}
      public ParserException(string msg, Exception inner) : base(msg, inner) {}
  }
}
