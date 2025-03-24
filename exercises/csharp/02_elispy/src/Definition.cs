// @copyright 2018 Günter Kolousek

using System;
using System.Text.RegularExpressions;

namespace ko.lexer {

  public class Definition {
      public Definition(string type, string regex)
          : this(type, regex, false) {}

      public Definition (string type, string regex, bool is_ignored) {
          this.type = type;
          this.regex = new Regex(regex, RegexOptions.Compiled);
          this.is_ignored = is_ignored;
      }

      public bool is_ignored { get; private set; }
      public Regex regex { get; private set; }
      public string type { get; private set; }
  }
}
