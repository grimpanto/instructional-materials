using System;
using static System.Console;
using System.IO;
using static System.IO.Directory;

public class Program {
    public static void Main() {
        CreateDirectory("/tmp/data");
        try {
            Delete("/tmp/data");
        } catch (IOException) {
            WriteLine("not emty");  // if not empty...
        }
        if (Exists("/tmp/data"))
            Delete("/tmp/data", true);
        CreateDirectory("/tmp/data");
        File.Create(@"/tmp/data/test.txt");
        WriteLine(Exists("/tmp/data/test.txt"));  // -> False
        if (Exists("/tmp/dat"))
            Delete("/tmp/dat", true);
        Move("/tmp/data", "/tmp/dat");
        foreach (var dir in EnumerateDirectories("/tmp/dat"))
              WriteLine(dir);  // -> /tmp/dat/data2
        string[] dirs=GetDirectories("/tmp/dat");
        foreach (var file in EnumerateFiles("/tmp/dat"))
            WriteLine(file);  // -> /tmp/dat/test.txt
        WriteLine(GetCurrentDirectory());  // z.B. /home/maxi
        WriteLine(GetParent(GetCurrentDirectory()));  // z.B. /home
    }
}
