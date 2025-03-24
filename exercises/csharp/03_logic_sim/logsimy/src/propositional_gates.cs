// @copyright 2018 Günter Kolousek

namespace logsimy {
  namespace propositional {
    namespace gates {

      delegate bool BooleanLogicOp(bool op1, bool op2);

      abstract class BooleanLogicGate2 {
          private bool i0_set;
          private bool i1_set;
          private bool _i0;
          private bool _i1;
          private bool _o;

          public BooleanLogicOp op { get; set; }

          public bool i0 {
              get {
                  return _i0;
              }
              set {
                  _i0 = value;
                  i0_set = true;
                  if (i1_set) {
                      _o = op(_i0, _i1);
                  }
              }
          }

          public bool i1 {
              get {
                  return _i1;
              }
              set {
                  _i1 = value;
                  i1_set = true;
                  if (i0_set) {
                      _o = op(_i0, _i1);
                  }
              }
          }

          public bool o {
              get {
                  return _o;
              }
              set {
                  _o = value;
              }
          }
      }

      class AndGate2 : BooleanLogicGate2 {
          public AndGate2() {
              op = logics.propositional.Operators.conj;
          }
      }

    }
  }
}
