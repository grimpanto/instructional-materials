using System;
using static System.Console;
using System.IO;
using static System.IO.Path;

public class Program {
    public static void Main() {
        string p1=Combine(GetTempPath(), "test.txt");
        WriteLine(p1);  // -> /tmp/test.txt
        string[] labels=new string[]{"/tmp", "data", "test.dat"};
        string p2=Combine(labels);
        WriteLine(p2);  // -> /tmp/data/test.dat
        p2 = ChangeExtension(p2, "txt");
        WriteLine(GetExtension(p2));  // -> .txt
        WriteLine(GetFileName(p2));  // -> test.txt
        WriteLine(GetFileNameWithoutExtension(p2));  // -> test
        WriteLine(GetDirectoryName(p2));  // -> /tmp/data
        WriteLine(GetTempFileName());  // z.B.: /tmp/tmp38c55ebc.tmp
        WriteLine(GetTempPath());  // -> /tmp/
        // kryptographisch sicher:
        WriteLine(GetRandomFileName());  // z.B.: vf1ernld.b7e
        WriteLine(HasExtension("/tmp/data"));  // -> False
        WriteLine(IsPathRooted("/tmp/data/test.txt"));  // -> True
        WriteLine(IsPathRooted("data/test.txt"));  // -> False
    }
}
