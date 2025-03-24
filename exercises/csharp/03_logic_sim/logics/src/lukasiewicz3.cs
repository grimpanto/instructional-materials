// @copyright 2018 Günter Kolousek

namespace logics {
  namespace lukasiewicz3 {
    public static class Operators {
        public static bool? conj(bool? op1, bool? op2) {
            if (op1.HasValue && !op1.Value)
                return false;
            if (op2.HasValue && !op2.Value)
                return false;
            if (op1 == op2)
                return op1;
            return null;
        }

        public static bool? disj(bool? op1, bool? op2) {
            if (op1.HasValue && op1.Value)
                return true;
            if (op2.HasValue && op2.Value)
                return true;
            if (op1 == op2)
                return op1;
            return null;
        }

        public static bool? anti(bool? op1, bool? op2) {
            return conj(disj(op1, op2), neg(conj(op1, op2)));
        }

        public static bool? neg(bool? op) {
            if (!op.HasValue)
                return op;
            return !op;
        }

        public static bool? imp(bool? op1, bool? op2) {
            if (op1.HasValue)
                if (!op1.Value)
                    return true;
                else
                    return op2;
            if (op2.HasValue && !op2.Value)
                return null;
            return true;
        }

        public static bool? equiv(bool? op1, bool? op2) {
            return conj(imp(op1, op2), imp(op2, op1));
        }
    }
  }
}
