// @copyright 2018 Günter Kolousek

namespace ko.lexer {
  using System;
  using System.Collections.Generic;
  using System.Text.RegularExpressions;

  public class Lexer : ILexer {
      Regex eol = new Regex(@"\r\n|\r|\n",  RegexOptions.Compiled);
      IList<Definition> token_defs = new List<Definition>();

      public void add_definition(Definition definition) {
          token_defs.Add(definition);
      }

      public IEnumerable<Token> tokenize(string source) {
          int curr_idx = 0;
          int curr_line = 1;
          int curr_col = 0;

          while (curr_idx < source.Length) {
              Definition matched_def=null;
              int matched_len=0;

              foreach (var def in token_defs) {
                  var match = def.regex.Match(source, curr_idx);

                  //if (match.Success && (match.Index - curr_idx) == 0) {
                  if (match.Success && (match.Index == curr_idx)) {
                      matched_def = def;
                      matched_len = match.Length;
                      break;
                  }
              }

              if (matched_def == null) {
                  throw new LexerException(string.Format("Unrecognized symbol '{0}' at {1}",
                      source[curr_idx], new Position(curr_idx, curr_line, curr_col)));
              } else {
                  var value = source.Substring(curr_idx, matched_len);

                  // any white space character will be ignored
                  if (!matched_def.is_ignored)
                      yield return new Token(matched_def.type, value, new Position(curr_idx, curr_line, curr_col));

                  // calculating the next current column
                  // maybe the token is a whitespace token containing an eol
                  var eol_match = eol.Match(value);
                  if (eol_match.Success) {
                      // fine, so continue on the next line
                      curr_line += 1;
                      // maybe the lexeme would be " \r\n  ", so the next current column
                      // has to be calculate in the following way:
                      curr_col = value.Length - (eol_match.Index + eol_match.Length);
                  } else {
                      curr_col += matched_len;
                  }

                  curr_idx += matched_len;
              }
          }
      }
  }
}
