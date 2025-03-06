
using System;

class Program {    
    enum Color {
        red,
        green,
        blue
    }
    
    static void Main() {
        Color c1=Color.red;
        Console.WriteLine(c1);  // -> red
        Console.WriteLine($"{c1:D}");  // -> 0
        int i=(int)c1;
        Console.WriteLine(i);  // -> 0
        Color red;
        if (Enum.TryParse<Color>("red", out red))
            Console.WriteLine(red);  // -> red

        foreach (var c in Enum.GetNames(typeof(Color)))
            Console.WriteLine(c);  // -> red green blue
    }
}
