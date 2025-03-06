using System;
using System.Collections.Generic;

// contra-variant interface
interface IQueue<in T> {}

class Queue<T> : IQueue<T> {}

class Program {
    static void doit(IQueue<String> q) {}
    static void Main() {
        IQueue<Object> iobj=new Queue<Object>();
        IQueue<String> istr=new Queue<String>();
        // contra-variant!
        doit(iobj);
    }
}
