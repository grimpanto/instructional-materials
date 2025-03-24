// @copyright 2018 Günter Kolousek

namespace ko.elispy {
  using System;
  using System.Collections.Generic;
  using System.Linq;

  using ko.lexer;

  public abstract class Sexp {
      public bool is_quoted;
      public Position? position;

      protected Sexp(Position? position, bool is_quoted=false) {
          this.position = position;
          this.is_quoted = is_quoted;
      }

      public abstract Sexp eval(Context ctx=null);

      public override String ToString() {
          if (is_quoted) return "'";
          else return "";
      }

      // conversion methods
      public static explicit operator int(Sexp sexp) {
          SexpInteger res=sexp as SexpInteger;
          if (res != null)
              return res.value;
          else
              throw new ArgumentException($"Expected an int but got: {sexp}");
      }

      public static explicit operator string(Sexp sexp) {
          SexpString res=sexp as SexpString;
          if (res != null)
              return res.value;
          else
              throw new ArgumentException($"Expected a string but got: {sexp}");
      }

      public static implicit operator Sexp(int value) {
          return new SexpInteger(value);
      }

      public static implicit operator Sexp(string value) {
          return new SexpString(value);
      }

      // equality
      public static bool operator==(Sexp lhs, Sexp rhs) {
          if (Object.ReferenceEquals(lhs, null)) {
              if (Object.ReferenceEquals(rhs, null)) {
                  return true;
              }
              return false;
          }
          // Equals handles case of null on right side.
          return lhs.Equals(rhs);
      }

      public static bool operator!=(Sexp lhs, Sexp rhs) => !(lhs == rhs);

      public override int GetHashCode() =>
        is_quoted.GetHashCode();  // ^ position.GetHashCode();

      public override bool Equals(object o) {
          return this.Equals(o as Sexp);
      }

      public virtual bool Equals(Sexp o) {
          // Check for null values and compare run-time types.
          if (o == null || GetType() != o.GetType())
              return false;
          return is_quoted == o.is_quoted;
      }

      public static explicit operator bool(Sexp sexp) {
          return !sexp.is_null();
      }

      public abstract bool is_null();
      public abstract void accept(CodeGenerator cg);
  }


  public abstract class SexpAtom : Sexp {
      public SexpAtom(dynamic value, Position? position) : base(position) {
          this.value = value;
      }

      public dynamic value {
          get;
      }

      public override Sexp eval(Context ctx=null) {
          return this;
      }

      public override bool Equals(Object o) {
          return this.Equals(o as SexpAtom);
      }

      public override bool Equals(Sexp o) {
          return base.Equals(o) && value == ((SexpAtom)o).value;
      }

      public override int GetHashCode() {
          return base.GetHashCode() ^ value.GetHashCode();
      }

      public override bool is_null() {
          return false;
      }
  }


  public class SexpSymbol : SexpAtom {
      public SexpSymbol(string name, Position? position=null) :
          base(name, position) {
      }

      public override Sexp eval(Context ctx=null) {
          try {
              if (is_quoted)
                  return new SexpSymbol(value);
              else
                  return (Sexp)ctx.symtab[(string)value];
          } catch (Exception e) {
              throw new InterpreterException($"Symbol \"{value}\" not defined at {position}", e);
          }
      }

      public override string ToString() {
          return base.ToString() + $"{value}";
      }

      public override bool is_null() {
          return (value == "nil");
      }

      public override void accept(CodeGenerator cg) {
          cg.visit(this);
      }
  }


  public class SexpString : SexpAtom {
      public SexpString(string value, Position? position=null) :
          base(value.Replace("\"", ""), position) {}

      public override string ToString() {
          return base.ToString() + $"\"{value}\"";
      }

      public override void accept(CodeGenerator cg) {
          cg.visit(this);
      }
  }


  public class SexpInteger : SexpAtom {
      public SexpInteger(int value, Position? position=null) : base(value, position) {}

      public override string ToString() {
          return base.ToString() + $"{value}";
      }

      public override void accept(CodeGenerator cg) {
          cg.visit(this);
      }
  }


  public class SexpList : Sexp {
      internal List<Sexp> terms;

      //public SexpList(Position? position=null)
      public SexpList(Position? position=null, bool is_quoted=false)
          : base(position, is_quoted) {
          terms = new List<Sexp>();
      }

      public SexpList(List<Sexp> terms, Position? position=null, bool is_quoted=false)
          : base(position, is_quoted) {
          this.terms = terms;
      }

      public void add_term(Sexp term) {
          terms.Add(term);
      }

      public override Sexp eval(Context ctx=null) {
          if (is_quoted)
              return new SexpList(terms);

          // otherwise treat first item as function
          // if no function available...
          if (terms.Count == 0)
              return ctx.symtab["nil"];  // return this ... if nil=()!

          // so, the first item must be a symbol that denote
          // a function... otherwise -> Error
          if (!(terms[0] is SexpSymbol))
            throw new InterpreterException(
              $"First item must be a symbol, but got \"{terms[0]}\" at {position}");

          try {
              return ctx.functab[((SexpSymbol)terms[0]).value].call(
                terms.GetRange(1, terms.Count - 1), ctx);
          } catch (Exception e) {
              throw new InterpreterException(
                $"{this} could not be evaluated at {position}", e);
          }
      }

      public override bool Equals(Object o) {
          return this.Equals(o as SexpList);
      }

      public override bool Equals(Sexp o) {
          return base.Equals(o) && terms.SequenceEqual(((SexpList)o).terms);
      }

      public override int GetHashCode() {
          return base.GetHashCode() ^ terms.GetHashCode();
      }

      public override string ToString() {
          string res="";
          if (terms.Count > 0) {
              res = "(";
              for (int i=0; i < terms.Count; ++i) {
                  if (i == terms.Count - 1)
                      res += (terms[i].ToString());
                  else
                      res += (terms[i].ToString() + " ");
              }
              res += ")";
          } else
              res += "nil";

          return base.ToString() + $"{res}";
      }

      public override bool is_null() {
          return terms.Count == 0;
      }

      public override void accept(CodeGenerator cg) {
          cg.visit(this);
      }
  }
}
