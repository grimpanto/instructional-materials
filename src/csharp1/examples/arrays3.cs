
using System;

class Program {    
    static void Main() {
        Array arr = Array.CreateInstance(typeof(int), 3);
        arr.SetValue(1, 0);
        arr.SetValue(2, 1);
        arr.SetValue(3, 2);
        Console.WriteLine(arr.GetValue(1));  // -> 2
        Array arr2=(int[])arr.Clone();  // shallow copy!
        // deep copy needed? -> iterate!
    }
}
