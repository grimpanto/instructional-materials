using System;
using static System.Console;
using System.Collections.Generic;

public class Program {
    public static void Main() {
        var phonebook=new Dictionary<string, int>(){
            ["maxi"]=4711,
            ["mini"]=4712
        };
        WriteLine(phonebook["mini"]);
        try {
            WriteLine(phonebook["otto"]);
        } catch (KeyNotFoundException e) {
            WriteLine(e.Message);
        }
        foreach (var key in phonebook.Keys)
            Write($"{key} ");
        foreach (var value in phonebook.Values)
            Write($"{value} ");
        phonebook["otto"] = 4713;
        phonebook.Remove("mini");
        WriteLine(phonebook.ContainsKey("mini")); // -> False
        WriteLine(phonebook.ContainsValue(4713)); // -> True
    }
}
