package IteratorPattern;

import java.util.ArrayList;

public class BrowerHistory {
    private String[] urls = new String[10];
    private int count;


    public String[] getUrls() {
        return urls;
    }

    public void setUrls(String[] urls) {
        this.urls = urls;
    }

    public void push(String url){
        urls[count++] = url;
    }

    public String pop(){
        return urls[--count];
    }

    public Iterator createIterator(){
        return new ArrayIterator(this);
    }

    public class ArrayIterator implements Iterator {
        BrowerHistory history;
        int index;

        public ArrayIterator(BrowerHistory history) {
            this.history = history;
            index = 0;
        }


        @Override
        public boolean hasNext() {
            return index < history.count;
        }

        @Override
        public String current() {
            return history.urls[index];
        }

        @Override
        public void next() {
            index++;
        }
    }
}
