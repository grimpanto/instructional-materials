public class MyThread3 implements Runnable {
    public void run() {
        int i=0;
        while (i < 10) {
            System.out.print("A");
            Thread.yield();  // static!
            i++;
        } }
    public static void main(String[] args) {
        MyThread3 t=new MyThread3();
        new Thread(t).start();
        int i=0;
        while (i < 10) {
            System.out.print("B");
            Thread.yield();
            i++;
        } } }
