using System;
public class Test {
    public static void Main() {
        Car c = new Car(); c.incr(125);
        //c.speed = 123;  // -> error
        System.Console.WriteLine(c.speed);
        c.incr(125);
        System.Console.WriteLine(c.speed);
    }
}

public class Car {
    public int speed {  // auto-implemented
        get;
        private set;
    }
    
    public void incr(int delta) {
        speed = speed + delta;
    }
}
