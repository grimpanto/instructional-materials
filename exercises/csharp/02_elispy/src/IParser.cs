// @copyright 2018 Günter Kolousek

using System;
using System.Collections.Generic;

namespace ko.elispy {
  public interface IParser {
      List<Sexp> parse(string source);
  }
}
