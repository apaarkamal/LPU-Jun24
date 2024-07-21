package Concurrency.MergeSort;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class Main {
    public static void main(String[] args) throws Exception {
        List<Integer> l = new ArrayList<>(List.of(3, 6, 8, 3, 6 ,1, 2, 5, 3));
        ExecutorService executor = Executors.newCachedThreadPool();

        MergeSort sorter = new MergeSort(l, executor);
        Future<List<Integer>> futureSortedArr = executor.submit(sorter);

        System.out.println(futureSortedArr.get());
    }
}
