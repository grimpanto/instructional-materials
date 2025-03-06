using System;
using static System.Console;

public class Program {
    public static void Main() {
        int i=0;
        int j=0;
        try {
            WriteLine(i / j);
        } catch (DivideByZeroException e) {
            WriteLine($"{e.Message}");
        } catch {
            WriteLine("catch all");
        } finally {
            WriteLine("finally");
        }
    }
}
