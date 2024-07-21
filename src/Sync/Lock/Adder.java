package Sync.Lock;

import java.util.concurrent.locks.Lock;

public class Adder implements Runnable {
    Counter counter;
    Lock lock;
    Adder(Counter counter, Lock lock){
        this.counter = counter;
        this.lock = lock;
    }
    @Override
    public void run() {
        for (int i = 0; i < 10000000; i++) {

            // lock use and example
//            lock.lock();
//            // critical section start
//            counter.count += 1;
//            // critical section end
//            lock.unlock();


            counter.increment();


        }
    }
}
