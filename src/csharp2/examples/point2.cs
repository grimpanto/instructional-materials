
using System;

//                   type-safe Equals(o)
public struct Point : IEquatable<Point> {
    public Point(double _x, double _y) { x = _x; y = _y; }
    public double x { get; }
    public double y { get; }
    public override string ToString() => $"Point({x},{y})";

    // Override the equality operator (==) if your type is a base
    // type such as a Point, String,... 
    public static bool operator==(Point lhs, Point rhs) {
        return lhs.Equals(rhs);
    }

    public static bool operator!=(Point lhs, Point rhs) => !(lhs == rhs);    

    public override int GetHashCode() =>
      x.GetHashCode() ^ y.GetHashCode();
    
    public override bool Equals(object o) {
        return this.Equals((Point)o);
    }

    public bool Equals(Point o) {
        // Check for null values and compare run-time types.
        if (GetType() != o.GetType()) 
            return false;
        return (x == o.x) && (y == o.y);
    }
}

public class Program {
    static public void Main() {
        Point p1=new Point(1, 1);
        Point p2=new Point(1, 1);
        Point p3=new Point(1, 2);
        Console.WriteLine($"{p1 == p2} | {p1 == p3}");
    }
}
