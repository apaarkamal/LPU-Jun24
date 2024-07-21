package Generics;

public class BoundedBox<T extends Number> {
    T x;
    BoundedBox(T x){
        this.x = x;
    }

    @Override
    public String toString() {
        return "BoundedBox{" +
                "x=" + x +
                '}';
    }
}
