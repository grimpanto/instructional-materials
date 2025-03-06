using System;
using static System.Console;
using System.IO;

public class Program {
    public static void Main() {
        var f=new FileInfo("/tmp/test.txt");
        StreamWriter w=f.CreateText();  // UTF-8
        WriteLine(w.Encoding);  // -> System.Text.UTF-8Encoding
        w.Write("abc");
        w.WriteLine('d');
        w.Write(4711);
        // ... a la Console.Write
        w.Close();
        StreamReader r=f.OpenText();  // UTF-8
        Write((char)r.Read());  // next char -> a
        WriteLine(r.ReadLine());  // -> bcd
        WriteLine(r.ReadToEnd());  // -> 4711
    }
}
