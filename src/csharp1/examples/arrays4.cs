
using System;

class Program {    
    static void Main() {
        string[] names={
            "hugo",
            "mini",
            "maxi",
            "anne",
            "anneliese"
        };
        Array.Sort(names);
        foreach (var n in names)
            Console.WriteLine(n);
    }
    // class? -> interface IComparable
    //        -> method CompareTo
}
