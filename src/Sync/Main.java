package Sync;

public class Main {
    public static void main(String[] args) throws InterruptedException {
        Counter counter  = new Counter();

        Thread t1 = new Thread(new Buyer(counter));
        Thread t2 = new Thread(new Seller(counter));

        t1.start();

//        Thread.sleep(1000);
        // cnt=-1000;

        t2.start();

//        t1.join();
//        t2.join();

//        Thread.sleep(1000);

        System.out.println(counter.cnt);
    }
}
