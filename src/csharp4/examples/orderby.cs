using System;
using System.Collections.Generic;
using System.Linq;

class Person {
    public string first_name;
    public string last_name;
    public Person(string _first_name, string _last_name) {
        first_name = _first_name;
        last_name = _last_name;
    }
    public override string ToString() => $"{last_name} {first_name}";
}


public class Program {
    public static void Main() {
        Person p=new Person("otto", "meier");

        List<Person> lst=new List<Person>{
            new Person("sam", "muster"),
            new Person("otto", "meier"),
            new Person("franz", "meier")
        };
        List<Person> sorted = lst.OrderBy(o=>o.last_name).ToList();
        foreach (var o in lst)
            Console.WriteLine(o);
    }
}
