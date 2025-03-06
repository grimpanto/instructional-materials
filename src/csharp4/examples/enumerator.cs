
using System;
using static System.Console;
using System.Collections.Generic;

public class Program {
    public static void Main() {
        string[] lines={"abc", "def", "ghi"};
        foreach (var line in lines)
                WriteLine(line);
        IEnumerator<string> lines_enum=((IEnumerable<string>)lines).GetEnumerator();
        while (lines_enum.MoveNext())
            WriteLine(lines_enum.Current);
    } }
