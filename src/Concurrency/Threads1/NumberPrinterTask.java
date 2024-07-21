package Concurrency.Threads1;

public class NumberPrinterTask implements Runnable{
    int number;
    public NumberPrinterTask(int num){
        number=num;
    }
    @Override
    public void run() {
        System.out.println(Thread.currentThread().getName() + "->" + number);
    }
}
