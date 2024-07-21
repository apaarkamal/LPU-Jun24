package Concurrency.Threads1;

public class NewThread extends Thread {
    String name;
    public void setNewName(String name){
        this.name = name;
//        System.out.println("In New Thread");
    }
    public void run(){
        System.out.println(name + " is running");
    }
}
