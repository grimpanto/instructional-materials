using System;

public class Program {
    // default is "checked is off"
    // change it using compiler option: -checked+
    public static void Main() {
        float a=3.4e38f;
        float b=3.4e38f;
        Console.WriteLine(a + b);  // -> +unendlich
        
        // uint c=4294967295 + 1;  // -> comp error
        uint c=unchecked(4294967295 + 1);
        Console.WriteLine(c);  // -> 0
        
        uint d=4294967295;
        uint e=1;
        Console.WriteLine(d + e);  // -> 0
        checked {
            Console.WriteLine(d + e);
        }
        // -> System.OverflowException: Arithmetic\n
        //     operation resulted in an overflow.
    }
}
