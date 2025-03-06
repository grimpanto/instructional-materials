using System;
using static System.Console;
using System.IO;

public class Program {
    public static void Main() {
        var f=new FileInfo("/tmp/test.txt");

        using (TextWriter writer=f.CreateText()) {
            writer.WriteLine("abc");
            writer.WriteLine("def");
        }
        using (TextWriter writer=f.AppendText()) {
            writer.WriteLine("ghi");
        }
        using (TextReader reader=f.OpenText()) {
            while (reader.Peek() >= 0)
                WriteLine(reader.ReadLine());
        }
    } }
