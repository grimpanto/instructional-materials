using System;

public class Outer {

    int i=1;
    
    class Inner {  // -> default: private to Outer!
        Outer o;
        int j=2;
        public int result() {
            return o.i + j;
        }

        public Inner(Outer o) {
            this.o = o;
        }
    }

    public static void Main() {
        Outer o=new Outer();
        Inner n=new Inner(o);
        Console.WriteLine(n.result());
    } 
}
