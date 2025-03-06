using System;
using System.Collections.Generic;

class Person : IFormattable, IComparable<Person> {
    public string first_name;
    public string last_name;
    public Person(string _first_name, string _last_name) {
        first_name = _first_name;
        last_name = _last_name;
    }
    public override string ToString() => $"{first_name} {last_name}";
    public string ToString(string format, IFormatProvider format_provider) {
        if (format == null) format = "N";
        switch (format.ToUpper()) {
          case "N": return ToString();  // name
          case "F": return first_name;
          case "L": return last_name;
          default:
            throw new FormatException(String.Format(format_provider,
                $"Format {format} is not supported"));
        } 
    }
    public string ToString(string format) => ToString(format, null);

    public int CompareTo(Person o) {
        int cmp=last_name?.CompareTo(o?.last_name) ?? -1;
        if (cmp == 0)
            return first_name?.CompareTo(o?.first_name) ?? -1;
        return cmp;
    }
}

/*
  public class Program {
  public static void Main() {
  Person p=new Person("otto", "meier");
  System.Console.WriteLine(p);
  System.Console.WriteLine($"{p:F}");
  System.Console.WriteLine($"{p:L}");

  List<Person> lst=new List<Person>{
  new Person("otto", "meier"),
  new Person("franz", "meier"),
  new Person("sam", "muster")
  };
  lst.Sort();
  foreach (var o in lst)
  Console.WriteLine($"{o}");
  }
  }
*/
