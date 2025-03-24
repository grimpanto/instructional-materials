// @copyright 2018 Günter Kolousek

namespace logics {
  namespace propositional {
    public static class Operators {
        public static bool conj(bool op1, bool op2) {
            return op1 && op2;
        }
        public static bool disj(bool op1, bool op2) {
            return op1 || op2;
        }
        public static bool anti(bool op1, bool op2) {
            return op1 ^ op2;
        }
        public static bool neg(bool op) {
            return !op;
        }
        public static bool imp(bool op1, bool op2) {
            return disj(neg(op1), op2);
        }
        public static bool equiv(bool op1, bool op2) {
            return op1 == op2;
        }
    }
  }
}
