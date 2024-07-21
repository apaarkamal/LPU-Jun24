package Sync;

public class Seller implements Runnable {
    Counter counter;
    Seller(Counter counter){
        this.counter = counter;
    }

    @Override
    public void run() {
        for (int i = 0; i < 1000; i++) {
            counter.increment();
        }
    }
}
