using System;
using static System.Console;
using System.Collections.Generic;

public class Program {
    public static void Main() {
        List<int> even=new List<int>();
        even.Add(0);
        even.AddRange(new int[]{4,6,8,10});  // IEnumerable!
        even.Insert(1, 2);
        WriteLine(even[1]);  // -> 2
        even.Remove(0);
        foreach (var i in even)
              Write($"{i} ");
        WriteLine(); 
        List<int> odd=new List<int>{1,3,5,7,9,11}; 
        odd.RemoveAt(odd.FindIndex(i => i == 11));
        var all=new List<int>();
        all.AddRange(even);
        all.AddRange(odd);
        all.Sort();
        foreach (var i in all)
            Write($"{i} ");
    }
}
