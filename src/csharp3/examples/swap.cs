
using System;

public class Program {
    void swap<T> (ref T x, ref T y) {
        T tmp;
        tmp = x;
        x = y;
        y = tmp;
    }
    
    public static void Main() {
        Program prg=new Program();
        int i=1;
        int j=2;
        prg.swap<int>(ref i, ref j);
        Console.WriteLine($"{i}, {j}");
    }
}
