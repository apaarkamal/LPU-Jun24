package StrategyPattern;

public class PngCompressor implements Compressor{
    @Override
    public void compress() {
        System.out.println("compressed using PNG");
    }
}
