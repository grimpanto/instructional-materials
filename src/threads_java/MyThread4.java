public class MyThread4 implements Runnable {
    public void run() {
        int i=0;
        while (i < 10) {
            System.out.print("A"); Thread.yield(); i++;
        } }
    public static void main(String[] args) {
        MyThread4 my=new MyThread4();
        Thread t=new Thread(my);
        t.start();
        try { t.join(); } catch (InterruptedException e) {}
        int i=0;
        while (i < 10) {
            System.out.print("B");
            Thread.yield();
            i++;
        } } }