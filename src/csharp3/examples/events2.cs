using System;
using static System.Console;

public class AlarmEvtArgs : EventArgs {
    public AlarmEvtArgs(string _msg) {
        msg = _msg;
    }
    public string msg { get; }
}

public class AlarmMachine {
    public AlarmMachine(string _id) { id = _id; }
    
    public event EventHandler<AlarmEvtArgs> alarm_event;
    
    public void alarm_handler1(object sender, AlarmEvtArgs e) {
        WriteLine($"handler1: machine {((AlarmMachine)sender).id}: {e.msg}");
    }

    public void alarm_handler2(object sender, AlarmEvtArgs e) {
        WriteLine($"handler2: machine {((AlarmMachine)sender).id}: {e.msg}");
    }

    public void alarm() {
        alarm_event(this, new AlarmEvtArgs("Feuer!"));
    }
    private string id;
}

public class Program {
    public static void Main() {
        AlarmMachine am=new AlarmMachine("am1");
        am.alarm_event += am.alarm_handler1;
        am.alarm_event += am.alarm_handler2;

        am.alarm();
    }
}
