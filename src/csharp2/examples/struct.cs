using System;

struct X {
    public int x;
    public X(int p) { x = p; }
}

class Program {
    static void Main() {
        X x1;
        x1.x = 1;
        Console.WriteLine(x1.x); // -> 1
        X x2=new X(2);
        Console.WriteLine(x2.x); // -> 2
        X x3=new X { x = 3 };
        Console.WriteLine(x3.x); // -> 3
        X x4=new X();
        Console.WriteLine(x4.x); // -> 0
    }
};
