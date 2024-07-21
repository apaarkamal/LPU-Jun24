package Concurrency.Executors;

import Concurrency.Threads1.NumberPrinterTask;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Main {
    public static void main(String[] args) {
        ExecutorService executor = Executors.newCachedThreadPool();
        for (int i = 0; i < 1000; i++) {
            executor.execute(new NumberPrinterTask(i));
        }
        executor.shutdown();
    }
}
