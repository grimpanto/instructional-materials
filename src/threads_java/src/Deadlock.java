public class Deadlock extends Thread {
    Object r1=new Object();  Object r2=new Object();
    public void run() {
      synchronized (r1) {
        try { sleep(300); } catch (InterruptedException e) {}
        synchronized (r2) {}
      }
    }
    public static void main(String[] args) {
      Deadlock dl = new Deadlock();  dl.start();
      synchronized (dl.r2) {
        try { sleep(300); } catch (InterruptedException e) {}
        synchronized (dl.r1) {}
      }
      System.out.println("this smiley will not be shown: :-(");
    }
}
