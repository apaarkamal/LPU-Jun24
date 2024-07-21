package Concurrency.Callable;

import java.util.concurrent.Callable;

public class Adder implements Callable<Integer> {
    int a, b;
    Adder(int a, int b){
        this.a = a;
        this.b = b;
    }


    @Override
    public Integer call() throws Exception {
        return a+b;
    }
}
