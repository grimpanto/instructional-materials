using System;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;

[Serializable]
public class Employee {
    public int id;
    public string name;
    [NonSerialized]
    public int salary;
        
    // Default constructor
    public Employee() {
        id = 0;
        name = null;
        salary = 0;
    }
}

public class Program {
    public static void Main() {
        //Create a new Employee object
        Employee o=new Employee();
        o.id = 4711;
        o.name = "Maxi Muster";

        Stream stream = new FileStream("employee.dat", FileMode.Create, FileAccess.Write);
        BinaryFormatter bformatter = new BinaryFormatter();
            
        Console.WriteLine("Writing...");
        bformatter.Serialize(stream, o);
        stream.Close();

        o = null;
            
        stream = new FileStream("employee.dat", FileMode.Open, FileAccess.Read);
        bformatter = new BinaryFormatter();
        
        Console.WriteLine("Reading...");
        o = (Employee)bformatter.Deserialize(stream);
        stream.Close();
            
        Console.WriteLine("id: {0}", o.id);
        Console.WriteLine("name: {0}", o.name);
        Console.WriteLine("salary: {0}", o.salary);
    }
}
