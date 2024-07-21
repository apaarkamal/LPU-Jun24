package Interfaces;

public interface User {
    String getName();
    String getEmail();
    default void where(){
        System.out.println("I am inside Interface User");
    }
}
