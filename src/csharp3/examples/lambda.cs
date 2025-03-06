using System;

public class Program {
    public static void Main() {
        // mulple code lines
        Func<string, string> output=msg => {
            string ret="Hello, ";
            ret += msg;
            return ret;
        };
        Console.WriteLine(output("World"));
        // closures
        double offset=1;
        Func<double, double> adder=param => param + offset;
        Console.WriteLine(adder(1));  // -> 2
        offset = 2;
        Console.WriteLine(adder(1));  // -> 3
    }
}
