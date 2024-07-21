package Sync;

public class Buyer implements Runnable {
    Counter counter;
    Buyer(Counter counter){
        this.counter = counter;
    }

    @Override
    public void run() {
        for (int i = 0; i < 1000; i++) {
            counter.decrement();
        }
    }
}
