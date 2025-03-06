using System;
using System.Collections.Generic;

interface IQueue<out T> {}

class Queue<T> : IQueue<T> {}

class Program {
    static void Main() {
        IQueue<Object> iobj=new Queue<Object>();
        IQueue<String> istr=new Queue<String>();
        // covariant!
        // now it /will/ compile!
        iobj = istr;
    }
}
