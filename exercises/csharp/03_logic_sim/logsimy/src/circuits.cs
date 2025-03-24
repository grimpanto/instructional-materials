// @copyright 2018 Günter Kolousek

using static System.Console;

namespace logsimy {
  namespace circuits {
    using gates.propositional;
    using variables;

    public static class TestCircuits {
        public static void and3() {
            var i0=new Variable();
            var i1=new Variable();
            var i2=new Variable();
            var and1=new AndGate("and1");
            var and2=new AndGate("and2");
            Utilities.connect(i0, and1.i0);
            Utilities.connect(i1, and1.i1);
            Utilities.connect(and1.o, and2.i0);
            Utilities.connect(i2, and2.i1);
            Utilities.enable_logging(and2.o);

            i0.value = true;
            i1.value = true;
            i2.value = true;
        }
        public static void and_or() {
            var i0=new Variable();
            var i1=new Variable();
            var i2=new Variable();
            var and1=new AndGate("and1");
            var or1=new OrGate("or1");
            Utilities.connect(i0, and1.i0);
            Utilities.connect(i1, and1.i1);
            Utilities.connect(and1.o, or1.i0);
            Utilities.connect(i2, or1.i1);
            Utilities.enable_logging(or1.o);

            i0.value = true;
            i1.value = false;
            i2.value = true;
        }

        public static void flip_flop() {
            var s=new Variable();
            var r=new Variable();
            var nor1=new NOrGate("nor1");
            var nor2=new NOrGate("nor2");

            Utilities.connect(s, nor1.i0);
            Utilities.connect(nor2.o, nor1.i1);
            Utilities.connect(nor1.o, nor2.i0);
            Utilities.connect(r, nor2.i1);
            Utilities.enable_logging(nor2.o);

            s.reset();
            r.reset();

            nor1.reset(true);
            nor2.reset(false);
            nor2.i0.value=true;

            WriteLine("start flip-flopping");
            for (int i=0; i<4; ++i) {
                WriteLine("set: true");
                s.value = true;
                WriteLine("set: false");
                s.value = false;
                WriteLine("reset: true");
                r.value = true;
                WriteLine("reset: false");
                r.value = false;
            }
        }
    }
  }
}
