
using System;
using System.Collections.Generic;

class WorkStack<T> where T:new() {
    private T bottom=new T();
    private Stack<T> stack=new Stack<T>();
    public WorkStack() { stack.Push(bottom); }
    public void put(T e) { stack.Push(e); }
        public T get() { return stack.Pop(); }
}

public class HelloWorld {
    static public void Main() {
        WorkStack<int> ws=new WorkStack<int>();
        ws.put(1);
        ws.put(2);
        Console.WriteLine(ws.get());
        Console.WriteLine(ws.get());
        Console.WriteLine(ws.get());
    }
}
