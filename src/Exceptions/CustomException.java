package Exceptions;

public class CustomException {
    public static void main(String[] args) {
        try{
            validateAge(20);
        }catch (InvalidAgeException e){
            System.out.println(e.getMessage());
        }
    }
    static void validateAge(int age) throws InvalidAgeException {
        if(age<18){
            throw new InvalidAgeException("Age must be older than 18");
        }
        System.out.println("Age is valid");
    }
}
