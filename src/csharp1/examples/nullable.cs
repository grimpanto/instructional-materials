using System;

class Program {  // nullable types
    static void Main() {
        int x1=1;
        // Nullable<int> x2=null;  // for value types!
        int? x2=null; 
        Console.WriteLine(x2 + 1 == null);  // -> True
        Console.WriteLine(x1 != x2);  // -> True
        // be aware of: if-else!
        Console.WriteLine(x1 < x2);  // -> False
        int? x3=x1;  // implicit conversion
        //int x4=x3;  // comp error
        int x4=(int)x3;
        Console.WriteLine(x4);  // -> 1
        int x5=x3.HasValue ? x3.Value : -1;  // properties
        try {
            Console.WriteLine(x2.Value);
        } catch (System.InvalidOperationException) {
            Console.WriteLine(x2.GetValueOrDefault()); // -> 0
        }
        int x6=x3 ?? -1;  // coalescing operator 
    }
}
