// @copyright 2018 Günter Kolousek

using System;

namespace ko.lexer {
  public struct Position {
      public Position(int idx, int line, int column) {
          this.idx = idx;
          this.line = line;
          this.column = column;
      }

      public int column { get; private set; }
      public int idx { get; private set; }
      public int line { get; private set; }

      public override string ToString() {
          return string.Format("(index={0}, line={1}, column={2})",
            idx, line, column);
      }
  }
}
