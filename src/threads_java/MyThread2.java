public class MyThread2 extends Thread {
    public void run() {
        int i=0;
        while (i < 10) {
            System.out.print("A");
            yield();
            i++;
        } }
    public static void main(String[] args) {
        MyThread2 t=new MyThread2();
        t.start();
        int i=0;
        while (i < 10) {
            System.out.print("B");
            yield();
            i++;
        } } }