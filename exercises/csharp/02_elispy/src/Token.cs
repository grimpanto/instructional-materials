// @copyright 2018 Günter Kolousek

using System;

namespace ko.lexer {
  public struct Token {
      public Token(string type, string value, Position position) {
          this.type = type;
          this.value = value;
          this.position = position;
      }

      public Position position { get; set; }
      public string type { get; set; }
      public string value { get; set; }

      public override string ToString() {
          return string.Format("Token(type={0}, value={1}, position={2})",
            type, value, position);
      }
  }
}
