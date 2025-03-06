using System;
using static System.Console;
using System.IO;

public class Program {
    public static void Main() {
        try {
            using (FileStream f=new FileStream("/tmp/random.dat", FileMode.Create)) {
                for (byte i=65; i < 65+26; ++i)
                    f.WriteByte(i);
                f.Seek(7, SeekOrigin.Begin);
                Write((char)f.ReadByte());
                f.Seek(-4, SeekOrigin.Current);
                Write((char)f.ReadByte());
                f.Seek(6, SeekOrigin.Current);
                Write((char)f.ReadByte());
                f.Seek(-1, SeekOrigin.Current);
                Write((char)f.ReadByte());
                f.Seek(2, SeekOrigin.Current);
                Write((char)f.ReadByte());
            }
        } catch (Exception e) {
            WriteLine(e.Message);
        }
    }
}
