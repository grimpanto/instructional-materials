using System;
using System.Collections.Generic;

interface IQueue<T> {}

class Queue<T> : IQueue<T> {}

class Program {
    static void doit(IQueue<String> q) {}

    static void Main() {
        IQueue<Object> iobj=new Queue<Object>();
        IQueue<String> istr=new Queue<String>();
        // invariant!
        // will not compile -> Cannot implicitly convert type...
        iobj = istr;
        // will not compile ->  Argument 1: cannot convert from...
        doit(iobj);
    }
}
