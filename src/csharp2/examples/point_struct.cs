using System;

readonly struct Point {
    readonly public int x;
    readonly public int y;
    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
    public double distance() {
        return Math.Sqrt(x * x + y * y);
    }
    override public string ToString() { return $"({x}, {y})"; }
}

class Program {
    static void Main() {
        Point p1=new Point(1, 2);
        Console.WriteLine(p1); // -> (1, 2)
    }
};
