using System;
using System.Text;  // -> StringBuilder
using static System.Console;

public class Program {
    public static void Main() {
        var msg=" World!";
        StringBuilder sb=new StringBuilder("Hello");
        sb.Append(msg);
        WriteLine(sb);  // -> Hello World! (->ToString())
        WriteLine("{0}, {1}", sb.Capacity, sb.Length); // -> 16, 20
        sb = new StringBuilder(30);
        WriteLine(sb.Capacity);  // -> 30
        sb.Append("llx ");
        sb.Append('W');
        sb.Insert(0, "He");
        sb.Replace("x", "o");
        sb.AppendFormat("{0}", "orld!");
        WriteLine(sb);  // -> Hello World!
        sb = new StringBuilder("---", 30);
        sb.AppendLine();
        sb.Remove(0, 4);
        sb.AppendLine("hello World!");
        sb.Append(true);
        WriteLine(sb[0]);  // -> h
        sb[0] = 'H';
        WriteLine(sb);  // -> Hello World!\nTrue
    }
}
