package Concurrency.MergeSort;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.*;

public class MergeSort implements Callable<List<Integer>> {
    List<Integer> arr;
    ExecutorService executor;
    MergeSort(List<Integer> arr, ExecutorService executor){
        this.arr = arr;
        this.executor = executor;
    }

    @Override
    public List<Integer> call() throws Exception {
        if(arr.size()<=1) return arr;

        int mid = arr.size()/2;
        List<Integer> left = new ArrayList<>(List.of()), right = new ArrayList<>(List.of());
        for (int i = 0; i < arr.size(); i++) {
            if(i<mid) left.add(arr.get(i));
            else right.add(arr.get(i));
        }

//        ExecutorService executor = Executors.newCachedThreadPool();

        System.out.println(Thread.currentThread().getName());

        Future<List<Integer>> leftSortedFuture = executor.submit(new MergeSort(left, executor));
        Future<List<Integer>> rightSortedFuture = executor.submit(new MergeSort(right, executor));

        return mergeTwoSortedArrays(leftSortedFuture, rightSortedFuture);
    }

    private static List<Integer> mergeTwoSortedArrays(Future<List<Integer>> leftSortedFuture, Future<List<Integer>> rightSortedFuture) throws ExecutionException, InterruptedException {
        List<Integer> leftSorted = leftSortedFuture.get();
        List<Integer> rightSorted = rightSortedFuture.get();
        List<Integer> ans = new ArrayList<>();
        int i=0, j=0;
        while(i<leftSorted.size() && j<rightSorted.size()){
            if(leftSorted.get(i) < rightSorted.get(j)){
                ans.add(leftSorted.get(i));
                i++;
            }
            else{
                ans.add(rightSorted.get(j));
                j++;
            }
        }
        while(i<leftSorted.size()){
            ans.add(leftSorted.get(i));
            i++;
        }
        while (j<rightSorted.size()){
            ans.add(rightSorted.get(j));
            j++;
        }
        return ans;
    }
}
