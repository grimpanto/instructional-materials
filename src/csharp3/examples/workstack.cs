
using System;
using System.Collections.Generic;

class WorkStack<T> {
    //private T bottom=default(T);
    private T bottom=default;  // ab C#7.1: default
    private Stack<T> stack=new Stack<T>();
    public WorkStack() { stack.Push(bottom); }
    public void put(T e) { stack.Push(e); }
    public T get() { return stack.Pop(); }
}

public class Program {
    static public void Main() {
        WorkStack<int> ws=new WorkStack<int>();
        ws.put(1);
        ws.put(2);
        Console.WriteLine(ws.get());  // -> 2
        Console.WriteLine(ws.get());  // -> 1
        Console.WriteLine(ws.get());  // -> 0
    }
}
