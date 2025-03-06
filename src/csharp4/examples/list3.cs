using System;
using static System.Console;
using System.Collections.Generic;

public class Program {
    public static void Main() {
        List<int> l1=new List<int>{1, 2, 3};
        List<int> l2=new List<int>{1, 2, 3};
        WriteLine(l1.SequenceEqual(l2));
    }
}
