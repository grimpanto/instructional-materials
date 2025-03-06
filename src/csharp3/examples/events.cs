using System;


public class Program {
    public delegate void AlarmHandler(string msg);
    public static event AlarmHandler alarm;

    public static void alarm_handler1(string msg) {
        Console.WriteLine($"Handler1: {msg}");
    }

    public static void alarm_handler2(string msg) {
        Console.WriteLine($"Handler2: {msg}");
    }

    public static void Main() {
        alarm += alarm_handler1;
        alarm += alarm_handler2;

        alarm("Feuer!");
    }
}
