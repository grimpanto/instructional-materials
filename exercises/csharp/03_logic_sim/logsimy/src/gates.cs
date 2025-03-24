// @copyright 2018 Günter Kolousek

namespace logsimy {
  namespace gates {
    namespace propositional {
      using variables;
      using logics.propositional;

      public delegate bool BooleanOperator2(bool op1, bool op2);
      public delegate bool BooleanOperator1(bool op1);

      public abstract class Gate1 : Observer {
          public Gate1(string name, BooleanOperator1 op) {
              this.name = name;
              this.op = op;
              i = new Variable(name + ".i");
              o = new Variable(name + ".o");
              Utilities.inform(i, this);
          }
          private BooleanOperator1 op;
          public readonly string name;
          public Variable i {
              get; set;
          }
          public Variable o {
              get; set;
          }

          public virtual void update(Variable v, NotificationReason r) {
              if (r != NotificationReason.reset)
                  o.value = op(i.value);
              else
                  o.value = false;
          }

          public virtual void reset(bool out_val=false) {
              i.reset();
              o.reset(out_val);
          }
      }

      public class NegGate : Gate1 {
          public NegGate(string name) : base(name, Operators.neg) {
          }
          public override void reset(bool out_val=true) {
              base.reset(out_val);
          }
      }

      public abstract class Gate2 : Observer {
          public Gate2(string name, BooleanOperator2 op) {
              this.name = name;
              this.op = op;
              i0 = new Variable(name + ".i0");
              i1 = new Variable(name + ".i1");
              o = new Variable(name + ".o");
              Utilities.inform(i0, this);
              Utilities.inform(i1, this);
          }
          private BooleanOperator2 op;
          public readonly string name;
          public Variable i0 {
              get; set;
          }
          public Variable i1 {
              get; set;
          }
          public Variable o {
              get; set;
          }

          public virtual void update(Variable v, NotificationReason r) {
              if (r != NotificationReason.reset)
                  o.value = op(i0.value, i1.value);
          }

          public virtual void reset(bool out_val=false) {
              i0.reset();
              i1.reset();
              o.reset(out_val);
          }
      }

      public class AndGate : Gate2 {
          public AndGate(string name) : base(name, Operators.conj) {
          }
      }

      public class OrGate : Gate2 {
          public OrGate(string name) : base(name, Operators.disj) {
          }
      }

      public class XOrGate : Gate2 {
          public XOrGate(string name) : base(name, Operators.anti) {
          }
      }

      public class NOrGate : Gate2 {
          public NOrGate(string name) :
              base(name, (x, y) => Operators.neg(Operators.disj(x, y))) {
          }
          public override void reset(bool out_val=true) {
              base.reset(out_val);
          }
      }

      public class NAndGate : Gate2 {
          public NAndGate(string name) :
              base(name, (x, y) => Operators.neg(Operators.conj(x, y))) {
          }
          public override void reset(bool out_val=true) {
              base.reset(out_val);
          }
      }

      /*
      public class AndGate : Observer {
          public AndGate(string name) {
              this.name = name;
              i0 = new Variable(name + ".i0");
              i1 = new Variable(name + ".i1");
              o = new Variable(name + ".o");
              Utilities.inform(i0, this);
              Utilities.inform(i1, this);
          }
          public readonly string name;
          public Variable i0 {
              get; set;
          }
          public Variable i1 {
              get; set;
          }
          public Variable o {
              get; set;
          }
          public void update(Variable v, NotificationReason r) {
              if (r != NotificationReason.reset)
                  o.value = Operators.conj(i0.value, i1.value);
              else
                  o.value = false;
          }
      }*/
    }
  }
}
