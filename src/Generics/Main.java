package Generics;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class Main {

    public static<T> void printSomething(List<?> obj){
        for(Object item : obj){
            System.out.println(item);
        }
    }

    public static void main(String[] args) {
//        Box<Integer, String> b = new Box<>(1, "apaar");
//        System.out.println(b.toString());
//
//        Box<String, String> c = new Box<>("kamal", "apaar");
//        System.out.println(c.toString());
//
//        Box<String, ArrayList<Integer>> d=
//        new Box<>("abc", new ArrayList<>(List.of(1, 2, 3,4, 5)));
//        System.out.println(d.toString());

//        ArrayList<Integer> listInt = new ArrayList(List.of(1, 2, 3, 45));
//
//        ArrayList<Integer> listString = new ArrayList(List.of("a", "b", "c"));
//
        ArrayList<Object> listObject = new ArrayList(List.of(1, "b", 4.5,
                new Box<Integer, String>(1, "apaar")));

        printSomething(listObject);

//        BoundedBox<Double> a = new BoundedBox<Double>(4.67);
//        System.out.println(a.toString());


        // Implement OrderedPair<K, V> implement Pair<K, V>
        // Try implementing stack<T> of your own
    }
}
