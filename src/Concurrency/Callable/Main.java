package Concurrency.Callable;

import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class Main {
    public static void main(String[] args) throws ExecutionException, InterruptedException {
        ExecutorService executor = Executors.newCachedThreadPool();
        Adder a1 = new Adder(2, 3);

        Future<Integer> result = executor.submit(a1);

        System.out.println(result.get());

        executor.shutdown();
    }
}
