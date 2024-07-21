package LambdaAndStreams;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.Stream;

public class Main {
    public static void main(String[] args) {
//        List<String> myList = new ArrayList<>();
//        myList.add("Java");
//        myList.add("Python");
//        myList.add("C++");
//
//        Collections.sort(myList, (a, b) -> b.compareTo(a));
//        System.out.println(myList);

//        List<String> myList = Arrays.asList("Apple", "Banana", "Orange", "Mango");
//
//        List<String> filteredList = myList.stream()
//                .filter(fruit -> fruit.startsWith("A"))
//                .map(String::toUpperCase)
//                .collect(Collectors.toList());
//        filteredList.stream().forEach(System.out::println);

        IntStream intStream = IntStream.rangeClosed(1, 10);
        Integer evenSum = intStream
                .filter(number -> number%2==0)
                .reduce(0, (num1, num2) -> num1+num2);
        System.out.println(evenSum);
//        evenIntegers.forEach(System.out::println);
    }
}
