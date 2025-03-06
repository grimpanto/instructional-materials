using System;

public class Shape {
    private int x;
    private int y;
    public void move(int dx=1, int dy=1) {
        x += dx;
        y += dy;
    }
    public static void Main() {
        var shape=new Shape();
        shape.move();
        shape.move(dy:2, dx:1);
        Console.WriteLine(shape.x + ", " + shape.y);
    }
}
