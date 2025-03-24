// @copyright 2018 Günter Kolousek

using System;

namespace logics {
  namespace lukasiewiczn {
    public static class Operators {
        public static double conj(double op1, double op2) {
            return Math.Min(op1, op2);
        }
        public static double disj(double op1, double op2) {
            return Math.Max(op1, op2);
        }
        public static double anti(double op1, double op2) {
            return conj(disj(op1, op2), neg(conj(op1, op2)));
        }
        public static double neg(double op) {
            return 1 - op;
        }
        public static double imp(double op1, double op2) {
            return Math.Min(1, 1 + op2 - op1);
        }
        public static double equiv(double op1, double op2) {
            return 1 - Math.Abs(op1 - op2);
        }
    }
  }
}
