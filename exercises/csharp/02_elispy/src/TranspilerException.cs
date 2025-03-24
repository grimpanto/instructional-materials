// @copyright 2018 Günter Kolousek

namespace ko.elispy {
  using System;

  class TranspilerException : Exception {
      public TranspilerException() {}
      public TranspilerException(string msg) : base(msg) {}
      public TranspilerException(string msg, Exception inner) : base(msg, inner) {}
  }
}
