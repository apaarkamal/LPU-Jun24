package Exceptions;

import java.io.FileNotFoundException;
import java.io.FileReader;

public class FileReaderMethodExample {
    public static void main(String[] args) {
        try {
            readFile("example.txt");
        } catch (FileNotFoundException e) {
            // suppress exception
            // log the exception
            throw new RuntimeException(e);
        } catch (java.lang.ArithmeticException e) {
            throw  e;
        }
//         if works start from this place
    }

    static void readFile(String filename) throws FileNotFoundException, java.lang.ArithmeticException {
        FileReader fileReader = new FileReader(filename);
        // Code to read file
        try{
            int a = 10/0;
        }
        catch(java.lang.ArithmeticException e) {
            throw e;
        }
    }
}
