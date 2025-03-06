using System;
using static System.Console;
using System.IO;

public class Program {
    public static void Main() {
        File.Create(@"/tmp/test.txt");  // empty!
        File.Delete(@"/tmp/test.txt");
        WriteLine(File.Exists(@"/tmp/test.txt"));  // -> False 
        File.WriteAllLines(@"/tmp/test.txt", new string[] {"a", "b"});
        File.AppendAllText(@"/tmp/test.txt", "c\nd\n");
        string[] lines=File.ReadAllLines(@"/tmp/test.txt");
        string text=File.ReadAllText(@"/tmp/test.txt");
        WriteLine(text); // -> a\nb\nc\nd\n\n
        File.Delete(@"/tmp/test2.txt");
        File.Move(@"/tmp/test.txt", @"/tmp/test2.txt");
        File.Copy(@"/tmp/test2.txt", @"/tmp/test.txt");
        try {
            File.Copy(@"/tmp/test2.txt", @"/tmp/test.txt");
        } catch (IOException) {
            WriteLine("already exists");  // -> already...
        }
        File.Copy(@"/tmp/test2.txt", @"/tmp/test.txt", true);
    }
}
