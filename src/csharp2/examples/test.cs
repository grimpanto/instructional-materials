using System;

public class Program {
    public static void varpar(params int[] nums) {
        foreach (int num in nums) {
            Console.WriteLine(num);
        }
    }
    public static void Main() {
        int a=1;
        int b=2;
        int c=3;
        varpar(a, b, c);
        Console.WriteLine(a);
        Console.WriteLine(b);
        Console.WriteLine(c);
    }
}
