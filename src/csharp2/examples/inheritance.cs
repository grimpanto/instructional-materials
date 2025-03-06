using System;

public class Moveable {
    protected int x; protected int y;
    public Moveable(int x, int y) {
        this.x = x;
        this.y = y;
    }
    public virtual void move(int dx, int dy) {
        x += dx;
        y += dy;
        Console.WriteLine($"moved to {x},{y}");
    }
}

public class Car : Moveable {
    const int max_velocity=150;
    public int v;
    public Car(int x, int y, int v) : base(x, y) {
        this.v = v;
    }
    public Car(int x, int y) : this(x, y, max_velocity) {}
    public override void move(int dx, int dy) {
        Console.WriteLine("Car");
        base.move(dx, dy);
    }
}

public class Program {
    public static void Main() {
        Moveable m=new Car(0, 0);
        m.move(10, 20);
    }
}

