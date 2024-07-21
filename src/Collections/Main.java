package Collections;

import java.util.*;

public class Main {
    public static void main(String[] args) {
        List<String> myList = new ArrayList<>();
        myList.add("Java");
        myList.add("Python");
        myList.add("C++");
        Iterator<String> iterator = myList.iterator();
        while(iterator.hasNext()){
            System.out.println(iterator.next());
        }
//        System.out.println(myList);

//        Set<String> mySet = new HashSet<>();
//        mySet.add("C++");
//        mySet.add("Java");
//        mySet.add("Python");
//
//        System.out.println(mySet);

//        Map<String, Integer> myMap = new HashMap<>();
//        myMap.put("Java", 10);
//        myMap.put("C++", 20);
//        myMap.put("Python", 30);
//        System.out.println(myMap);

    }
}
