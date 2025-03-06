public class MyThread extends Thread {
    public void run() {
        int i=0;
        while (i < 10) {
            System.out.print("A");
            i++;
        } }
    public static void main(String[] args) {
        MyThread t=new MyThread();
        t.start();
        int i=0;
        while (i < 10) {
            System.out.print("B");
            i++;
        } } }