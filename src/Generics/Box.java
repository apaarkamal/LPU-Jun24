package Generics;

public class Box<T, U> {
    T x;
    U y;
    Box(T x, U y){
        this.x = x;
        this.y = y;
    }

    @Override
    public String toString() {
        return "Box{" +
                "x=" + x +
                ", y=" + y +
                '}';
    }
}
