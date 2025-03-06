
using System;

class Program {
    [Flags]
    enum DOW {
        monday=0x01,
        tuesday=0x02,
        wednesday=0x04,
        thursday=0x08,
        friday=0x10,
        saturday=0x20,
        sunday=0x40,
        weekend=saturday | sunday,
        workday=0x1f,
        allweek=workday | weekend
    }
    
    static void Main() {
        DOW d=DOW.monday;
        Console.WriteLine(d);  // -> monday
        Console.WriteLine(DOW.weekend);
        // -> weekend
        Console.WriteLine(DOW.monday | DOW.tuesday);
        // -> monday, tuesday
    }
}
