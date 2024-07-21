package StrategyPattern;

public class Main {
    public static void main(String[] args) {
        ImageStore img_store = new ImageStore();
        img_store.store(new JPEGCompressor(), new HighContrastFilter());

        img_store.store(new PngCompressor(), new HighContrastFilter());
    }
}
