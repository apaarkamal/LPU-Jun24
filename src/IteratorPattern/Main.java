package IteratorPattern;

public class Main {
    public static void main(String[] args) {
        BrowerHistory history = new BrowerHistory();
        history.push("a");
        history.push("b");
        history.push("c");

//        for (int i = 0; i < history.getUrls().size(); i++) {
//            System.out.println(history.getUrls().get(i));
//        }

        Iterator it = history.createIterator();
        while(it.hasNext()){
            System.out.println(it.current());
            it.next();
        }

    }
}
