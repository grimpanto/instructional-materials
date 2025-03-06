public class Account extends Thread {
    public int balance=15;

    boolean withdraw(int amount) {
        if (balance >= amount) {
          balance -= amount; return true;
        } else { return false; }
    }

    public void run() {
        System.out.print(withdraw(10) + " ");
    }

    public static void main(String[] args)
      throws InterruptedException {
        Account acc = new Account();  acc.start();
        System.out.print(acc.withdraw(6) + " ");
        acc.join();
        System.out.println(acc.balance);
    } }
