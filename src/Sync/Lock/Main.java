package Sync.Lock;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Main {
    public static void main(String[] args) throws InterruptedException {
        Counter counter = new Counter();
        Lock lock = new ReentrantLock();

        Adder adder = new Adder(counter, lock);
        Subrator subrator = new Subrator(counter, lock);

        Thread adderThread = new Thread(adder);
        Thread subractorThread = new Thread(subrator);

        adderThread.start();
        subractorThread.start();

        adderThread.join();
        subractorThread.join();

        System.out.println(counter.count);
    }
}
