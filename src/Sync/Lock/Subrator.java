package Sync.Lock;

import java.util.concurrent.locks.Lock;

public class Subrator implements Runnable {
    Counter counter;
    Lock lock;
    Subrator(Counter counter, Lock lock){
        this.counter = counter;
        this.lock = lock;
    }

    @Override
    public void run() {
        for (int i = 0; i < 10000000; i++) {
//            lock.lock();
//            // critical section begin
//            counter.count--;
//            // critical section end
//            lock.unlock();

            counter.decrement();

        }
    }
}
