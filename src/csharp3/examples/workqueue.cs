
using System;
using System.Collections.Generic;

class WorkQueue<T> {
    private Queue<T> queue=new Queue<T>(); 
    public void put(T e) { queue.Enqueue(e); }
    public T get() { return queue.Dequeue(); }
}

public class Program {
    static public void Main() {
        WorkQueue<int> wq=new WorkQueue<int>();
        wq.put(2);
        wq.put(1);
        Console.WriteLine(wq.get());
        Console.WriteLine(wq.get());
    }
}
