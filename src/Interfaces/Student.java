package Interfaces;

public interface Student {
    default void where(){
        System.out.println("I am inside Interface Student");
    }
}
