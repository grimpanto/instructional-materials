using static System.Console;
interface Moveable { void move(int x, int y); }
interface Moveable3D { void move(int x, int y); }

public class Car : Moveable, Moveable3D {
    int x; int y; int z;
    public void move(int x, int y) {
        this.x = x; this.y = y;
        WriteLine("Move to ({0}, {1})", x, y);
    }
    void Moveable3D.move(int x, int y) {  // kein public!
        move(x, y);  // das "normale" move
        this.z += 1;
        WriteLine("Move to ({0},{1},{2})", x, y, z);
    }

    public static void Main() {
        Car c=new Car();
        c.move(1,2);
        ((Moveable3D)c).move(1,2);
    }
}
