using System;
using static System.Console;
using System.Collections.Generic;

public class Program {
    public static void Main() {
        Stack<int> q=new Stack<int>();
        q.Push(0);
        q.Push(1);
        q.Push(2);
        q.Push(3);
        foreach (var i in q)
            Write($"{i} ");
        WriteLine(); 
        WriteLine(q.Count);  // -> 4
        WriteLine(q.Peek());  // -> 3
        WriteLine(q.Count);  // -> 4
        WriteLine(q.Pop());  // -> 3
        WriteLine(q.Count);  // -> 3
        q.Clear();
        WriteLine(q.Count);  // -> 0
    }
}
