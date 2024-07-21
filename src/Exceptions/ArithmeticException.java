package Exceptions;

public class ArithmeticException {
    public static void main(String[] args) {
        int result = 0;
        try{
            result = divide(10, 0);
        }catch (java.lang.ArithmeticException e){
            System.out.println(e.getMessage());
        }
        finally {
            result += 10;
        }
        System.out.println(result);
        // mutiple catch blocks
    }
    static int divide(int a, int b){
        return a/b;
    }
}
