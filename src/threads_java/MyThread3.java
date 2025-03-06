public class MyThread3 implements Runnable {
    public void run() {
        int i=0;
        while (i < 10) {
            System.out.print("A");
            Thread.yield();
            i++;
        } }
    public static void main(String[] args) {
        MyThread2 t=new MyThread2();
        new Thread(t).start();
        int i=0;
        while (i < 10) {
            System.out.print("B");
            Thread.yield();
            i++;
        } } }