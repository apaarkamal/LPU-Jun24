package Concurrency.Threads1;

public class Main {
    public static void main(String[] args) throws InterruptedException {
        System.out.println("Main starts");

        NewThread t1 = new NewThread();
        t1.setNewName("Thread-1");
        NewThread t2 = new NewThread();
        t2.setNewName("Thread-2");
        t1.start();
        t2.start();

//        System.out.println(Thread.currentThread().getName());

        // pause the current thread
        // main thread
        t1.join();
        t2.join();

        System.out.println("Main finishes");

//        for (int i = 1; i <= 100; i++) {
//            Thread t1 = new Thread(new NumberPrinterTask(i));
//            Thread.sleep(1000);
//            t1.start();
//        }
    }
}
