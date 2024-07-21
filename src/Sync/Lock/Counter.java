package Sync.Lock;

public class Counter {
    int count;
    Counter(){
        this.count=0;
    }
    // either use synchronised keyword
    public synchronized void increment(){
        count++;
    }
    public synchronized void decrement(){
        count--;
    }
}
