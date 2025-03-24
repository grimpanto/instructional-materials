// @copyright 2018 Günter Kolousek

namespace ko.elispy {
  using System;

  class InterpreterException : Exception {
      public InterpreterException() {}
      public InterpreterException(string msg) : base(msg) {}
      public InterpreterException(string msg, Exception inner) : base(msg, inner) {}
  }
}
