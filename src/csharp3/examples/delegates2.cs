using System;

public class Program {
    public delegate void Log(string msg);

    public static void error_log(string msg) {
        Console.Error.WriteLine(msg); }
    public static void out_log(string msg) {
        Console.WriteLine(msg); }
    public static void debug_log(string msg) {
        Console.Error.WriteLine($"Debug: {msg}"); }

    public static void Main() {
        Log log = error_log;
        log = log + out_log;
        log += debug_log;

        log("Hello, world");
    }
}
