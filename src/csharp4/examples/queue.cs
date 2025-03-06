using System;
using static System.Console;
using System.Collections.Generic;

public class Program {
    public static void Main() {
        Queue<int> q=new Queue<int>();
        q.Enqueue(0);
        q.Enqueue(1);
        q.Enqueue(2);
        q.Enqueue(3);
        foreach (var i in q)
            Write($"{i} ");
        WriteLine(); 
        WriteLine(q.Count);  // -> 4
        WriteLine(q.Peek());  // -> 0
        WriteLine(q.Count);  // -> 4
        WriteLine(q.Dequeue());  // -> 0
        WriteLine(q.Count);  // -> 3
        
        // -> InvalidOperationException: Collection was
        // modified after the enumerator was instantiated
        //foreach (var i in q)
        //    q.Dequeue();

        //for (int i=0; i<q.Count; i++)
        //    q.Dequeue();
        //WriteLine(q.Count);  // -> 1

        int cnt=q.Count;  // do it this way!
          for (int i=0; i<cnt; i++)
            q.Dequeue();
        WriteLine(q.Count);  // -> 0
    }
}
