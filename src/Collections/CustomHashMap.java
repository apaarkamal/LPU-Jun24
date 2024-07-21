package Collections;

import java.util.HashMap;
import java.util.Map;

public class CustomHashMap {
    public static void main(String[] args) {
        Map<Person, String> myMap = new HashMap<>();

        Person p1 = new Person(1, "Alice", 10);
        Person p2 = new Person(2, "Bob", 20);

        myMap.put(p1, "Girl");
        myMap.put(p2, "Boy");

        String gender = myMap.get(p1);
        System.out.println(gender);
    }
}
