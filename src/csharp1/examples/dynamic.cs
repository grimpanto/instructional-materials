
using System;

class Program {    
    static void Main() {
        dynamic dyn;
        dyn = 100;
        Console.WriteLine(dyn.GetType() + ": " + dyn);
        dyn = "abc";
        Console.WriteLine(dyn.GetType() + ": " + dyn);
        Console.WriteLine(dyn is string);  // -> True
        try {
            dyn.DoWhatIWant();
        } catch (Exception e) {
            Console.WriteLine(e.Message);
        }
    }
}
