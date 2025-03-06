
using System;
using System.Collections.Generic;

class WorkPacket {}

class WorkQueue<T> where T:WorkPacket {
    private Queue<T> queue=new Queue<T>(); 
    public void put(T e) { queue.Enqueue(e); }
    public T get() { return queue.Dequeue(); }
}

public class HelloWorld {
    static public void Main() {
        //WorkQueue<int> wq=new WorkQueue<int>();
        WorkQueue<WorkPacket> wq=new WorkQueue<WorkPacket>();
        wq.put(new WorkPacket());
        wq.put(new WorkPacket());
        Console.WriteLine(wq.get());  // -> WorkPacket
        Console.WriteLine(wq.get());  // -> WorkPacket
    }
}
