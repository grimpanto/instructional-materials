public class SafeAccount extends Thread {
    public int balance=15;

    synchronized boolean withdraw(int amount) {
        if (balance >= amount) {
          balance -= amount; return true;
        } else { return false; } }

    public void run() {
        System.out.print(withdraw(10) + " "); }

    public static void main(String[] args)
      throws InterruptedException {
        SafeAccount acc = new SafeAccount();  acc.start();
        synchronized (acc) {
            System.out.print(acc.withdraw(6) + " ");
        }
        acc.join();
        System.out.println(acc.balance); } }
