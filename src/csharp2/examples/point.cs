
using System;

//                   type-safe Equals(o)
public class Point : IEquatable<Point> {
    public Point(double _x, double _y) { x = _x; y = _y; }
    public double x { get; }
    public double y { get; }
    public override string ToString() => $"Point({x},{y})";

    // Override the equality operator (==) if your type is a base
    // type such as a Point, String,... 
    public static bool operator==(Point lhs, Point rhs) {
        if (Object.ReferenceEquals(lhs, null)) {
            if (Object.ReferenceEquals(rhs, null)) {
                return true;
            }
            return false;
        }
        // Equals handles case of null on right side.
        return lhs.Equals(rhs);
    }

    public static bool operator!=(Point lhs, Point rhs) => !(lhs == rhs);    

    public override int GetHashCode() =>
      x.GetHashCode() ^ y.GetHashCode();
    
    public override bool Equals(object o) {
        return this.Equals(o as Point);
    }

    public virtual bool Equals(Point o) {
        // Check for null values and compare run-time types.
        if (o == null || GetType() != o.GetType()) 
            return false;
        return (x == o.x) && (y == o.y);
    }
}


class Point3D: Point {
    int z;

    public Point3D(int x_, int y_, int z_) : base(x_, y_) {
        z = z_;
    }
    
    public override bool Equals(Object o) {
        return this.Equals(o as Point3D);
    }

    public override bool Equals(Point o) {
        return base.Equals(o) && z == ((Point3D)o).z;
    }

    public override int GetHashCode() {
        return base.GetHashCode() ^ z.GetHashCode();
    }

    /* not necessary anymore if Equals method become virtual!
    public static bool operator==(Point3D lhs, Point3D rhs) {
        if (Object.ReferenceEquals(lhs, null)) {
            if (Object.ReferenceEquals(rhs, null)) {
                return true;
            }
            return false;
        }
        // Equals handles case of null on right side.
        return lhs.Equals(rhs);
    }

    public static bool operator!=(Point3D lhs, Point3D rhs) => !(lhs == rhs);
    */
}

public class Program {
    static public void Main() {
        Point p1=new Point(1, 1);
        Point p2=new Point(1, 1);
        Point p3=new Point(1, 2);
        Console.WriteLine($"{p1 == p2} | {p1 == p3}");
        Point3D p4=new Point3D(1, 2, 3);
        Point3D p5=new Point3D(1, 2, 3);
        Point3D p6=new Point3D(1, 2, 4);
        Console.WriteLine($"{p4 == p5} | {p4 == p6}");
        Console.WriteLine($"{p1 == p4} | {p4 == p1}");
    }
}
