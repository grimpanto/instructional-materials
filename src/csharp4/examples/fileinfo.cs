using System;
using static System.Console;
using System.IO;

public class Program {
    public static void Main() {
        var f=new FileInfo("/tmp/test.txt");
        WriteLine(f.Exists);  // ?
        f.CreateText();
        f.Refresh();  // !
        WriteLine(f.Exists);  // -> True
        WriteLine(f.Name);  // -> test.txt
        WriteLine(f.Extension);  // -> .txt
        WriteLine(f.Directory);  // DirectoryInfo! -> /tmp
        WriteLine(f.DirectoryName);  // -> /tmp
        WriteLine(f.FullName);  // -> /tmp/test.text
        WriteLine(f.IsReadOnly);  // -> False
        WriteLine(f.Length);  // -> 0
        WriteLine(f.CreationTime);  // -> 17.07.2018 09:10:55
        WriteLine(f.LastAccessTime);
        WriteLine(f.LastWriteTime);
    }
}
