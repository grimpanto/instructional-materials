using System;
using static System.Console;
using System.IO;

public class Program {
    public static void Main() {
        var f=new FileInfo("test.txt");

        using (TextReader reader=f.OpenText()) {
            string line;
            while ((line = reader.ReadLine()) != null)
                WriteLine(line);
        }
        foreach (var line in File.ReadLines("test.txt"))
                WriteLine(line);
        // no method ReadLines in TextReader!!!
    } }
