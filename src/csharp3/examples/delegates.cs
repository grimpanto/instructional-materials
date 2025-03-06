using System;

delegate double Mean(double a, double b);

public class MeanCalculator {
    public double arith_mean(double a, double b) {
        return (a + b) / 2;
    }

    public double geom_mean(double a, double b) {
        return Math.Sqrt(a * b);
    }
}


public class Program {
    public static double arith_mean(double a, double b)
        => (a + b) / 2;
    
    public static void Main() {
        Mean mean = arith_mean;

        Console.WriteLine(mean(3, 5));
        MeanCalculator calc=new MeanCalculator();
        mean = calc.arith_mean;
        Console.WriteLine(mean(4, 6));
        mean = calc.geom_mean;
        Console.WriteLine(mean(6, 6));
    }
}
