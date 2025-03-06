using System;
using static System.Console;
using System.Collections.Generic;

public class Program {
    public static void Main() {
        var a=new HashSet<int>{1,2,3};
        var b=new HashSet<int>{2,3,4};
        if (!b.Add(4))
            WriteLine("4 already in set b!");
        WriteLine(a.IsSubsetOf(b)); // -> False
        WriteLine(b.IsSupersetOf(b)); // -> True
        WriteLine(a.Overlaps(b));  // -> True
        var a2=new HashSet<int>(a);
        a2.IntersectWith(b);
        foreach (var i in a2)
            Write($"{i} ");  // -> 2 3
        a2.UnionWith(b);  // a2 = {2,3,4}
        WriteLine(a2.Contains(3)); // -> True
        a2.Remove(3);
        a2.RemoveWhere(x => x % 2 == 0);
        WriteLine(a2.Count == 0);  // -> True
        a.ExceptWith(b);
        foreach (var i in a)
            Write($"{i} ");  // -> 1
        a.SymmetricExceptWith(b);
        foreach (var i in a)
            Write($"{i} ");  // -> 1 2 3 4
    }
}
