using System;

public class Program {
    public static void Main() {
        Console.WriteLine("{0}: bytes={1}, range=[{2},{3}]",
          typeof(float), sizeof(float), float.MinValue, float.MaxValue);
        Console.WriteLine("{0}: bytes={1}, range=[{2},{3}]",
          typeof(double), sizeof(double), double.MinValue, double.MaxValue);
        Console.WriteLine("{0}: bytes={1}, range=[{2},{3}]",
          typeof(decimal), sizeof(decimal), decimal.MinValue, decimal.MaxValue);
    }

}
