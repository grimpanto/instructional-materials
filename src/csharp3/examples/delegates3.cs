using System;

public class Program {
    public static void Main() {
        Action<string> log=msg => Console.WriteLine(msg);
        log("Hello, World");

        // x, y, return
        Func<double, double, double> mean=(x, y) => (x + y) / 2;
        Console.WriteLine(mean(3, 5));
    }
}
