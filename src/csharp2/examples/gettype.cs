
using System;

class Program {        
    static void Main() {
        int i=1;
        var type=i.GetType();
        Console.WriteLine(type);  // System.Int32
        Console.WriteLine(type.IsPrimitive); // -> True
    }
}
