using System;
using static System.Console;
using System.Collections.Generic;

public class Program {
    public static void Main() {
        List<Person> persons=new List<Person>();
        persons.Add(new Person("mini", "meier"));
        persons.AddRange(new Person[]{
              new Person("maxi", "meier"),
              new Person("mini", "osterhase"),
              new Person("otto", "huber")
          });
        // will not remove anything: Equals not impl!
        persons.Remove(new Person("otto", "huber"));
        // will be sorted correctly -> CompareTo
        persons.Sort();
        foreach (var p in persons)
              WriteLine($"{p}");
    }
}
