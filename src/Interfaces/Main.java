package Interfaces;

import java.util.*;

public class Main {
    public static void main(String[] args) {
        List<Person> list = new ArrayList<>();

        Person p = new Person("Kamal", "xyz@gmail.com");
        p.updateName("Vishal");
//        System.out.println(p.toString());
        Person u = new Person("Apaar", "xyz@yahoo.com");
//        System.out.println(u.toString());

        list.add(p);
        list.add(u);

        System.out.println(list);

        Collections.sort(list);

        System.out.println(list);

        u.where();

    }
}
