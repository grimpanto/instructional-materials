using System;
using static System.Console;
using System.Collections.Specialized;

public class Program {
    public static void Main() {
        var v1=new BitVector32();
        int bit0 = BitVector32.CreateMask();
        WriteLine(bit0);  // -> 1
        int bit1 = BitVector32.CreateMask(bit0);
        WriteLine(bit1);  // -> 2
        int bit2 = BitVector32.CreateMask(bit1);
        WriteLine(bit2);  // -> 4

        v1[bit0] = true;
        v1[bit2] = true;
        v1[8] = true;  // bit 3
        WriteLine(v1);  // -> BitVector32{000...1101}
        WriteLine(v1.Data);  // -> 13
        var v2=new BitVector32(13);
        WriteLine(v1.Data == v2.Data);  // -> True
        var v3=new BitVector32(0x0F);
        WriteLine(v3.Data);  // -> 15
    }
}
