
using System;
using static System.Console;

struct Person {
    public string last_name;
    public string first_name;
    public override String ToString() =>
      $"{last_name} {first_name}";
}

public class Program {
    public static void Main() {
        Person p;
        p.last_name = "muster";
        p.first_name = "maxi";
        
        var t=("maxi", 2, p);
        WriteLine($"{t.Item1}, {t.Item2}, {t.Item3}");
        
        (string s, int i, Person p) t2=("root", 1, p);
        WriteLine($"{t2.s}, {t2.i}, {t2.p}");
        
        var t3=(name:"mini", id:3, pers:p);
        WriteLine($"{t3.name}, {t3.id}, {t3.pers}");

        (var name, var id, var p2) = t3;
        WriteLine($"{name}, {id}, {p2}");

        (var name2, _, _) = t3;  WriteLine(name2);
    }
}
