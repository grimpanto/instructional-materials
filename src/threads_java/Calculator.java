class Rectangle {
    private int a;   private int b;
    public void set_sides(int a, int b) {
        this.a = a;
        try { Thread.currentThread().sleep(300); // demo only!
        } catch (InterruptedException e) {}
        this.b = b; }
    public int area() { return a * b; } }
    
public class Calculator extends Thread {
    private Rectangle rect;
    public void run() { rect.set_sides(1, 2); }
    public Calculator(Rectangle rect) { this.rect = rect; }
    public static void main(String[] args) {
        Rectangle rect=new Rectangle();  rect.set_sides(5, 5);
        Calculator calc=new Calculator(rect);  calc.start();
        System.out.print(rect.area() + " ");
        try { calc.join(); } catch (InterruptedException e) {}
        System.out.println(rect.area() + " ");
    } }