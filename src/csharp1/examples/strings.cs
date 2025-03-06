using System;
using static System.Console;

public class Program {
    public static void Main() {
        var msg="World";

        WriteLine($"Hello, \"{msg}\"");  // format string
        WriteLine(@"Hello, ""World""");  // verbatim string
        
        var res=string.Format("{0,10:C}", 1234.567M);
        WriteLine(res);  // currency
        WriteLine("{0,10:C2}", 1234.567M);
        WriteLine("{0,10:D6}", -1234);  // decimal
        WriteLine("{0,10:E2}", 1234.567M);  // exponential
        WriteLine("{0,10:F2}", 1234.567M);  // fixed-point
        WriteLine("{0,10:N1}", 1234.567M);  // number
        WriteLine("{0,10:X}", 123456);  // hexadecizmal
        DateTime local_date = DateTime.Now;
        WriteLine("{0:s}", local_date);        
    }
}
