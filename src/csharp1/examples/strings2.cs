
using static System.Console;

public class Program {
    public static void Main() {
        var msg="a,b,c,d,e";

        WriteLine(msg[0]);  // -> a
        WriteLine(msg.StartsWith("a,b"));  // -> True
        WriteLine(msg.IndexOf(",d"));  // -> 5
        WriteLine(msg.LastIndexOf(","));  // -> 7
        WriteLine(msg.Substring(2, msg.Length - 2));  // -> b,c,d,e
        WriteLine("  a,b,c,d,e   ".Trim() == msg);  // -> True
        WriteLine("  a,b,c,d,e   ".TrimStart().TrimEnd() == msg);  // -> True
        WriteLine(msg.Insert(0, "x,"));  // -> x,a,b,c,d,e
        WriteLine(msg.Replace(",", ";")); // -> a;b;c;d;e
        WriteLine(msg.Remove(2, 2));  // -> a,c,d,e
        WriteLine("[{0}]", string.Join(", ", msg.Split(",")));  // -> [a, b, c, d, e]
        WriteLine("X{0}X", "abc".PadLeft(5));  // -> X  abcX
//        Array.ForEach(msg.ToCharArray(), c => Write(c));  // -> a,b,c,d,e
    }
}
