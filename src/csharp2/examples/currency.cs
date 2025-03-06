using System;

class Currency {
    private decimal v;
    public Currency(decimal v_) =>
      v = v_;
    public static implicit operator double (Currency c) =>
        (double)c.v;
    public static explicit operator Currency (double v) =>
        new Currency((decimal)v);
    public override string ToString() =>
      v.ToString();
}

public class Program {
    public static void Main() {
        Currency c=new Currency(121.45m);
        Console.WriteLine(c + 2.006);
        Console.WriteLine((Currency)123.456);
    }
}
