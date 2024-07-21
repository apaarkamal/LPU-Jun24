package StrategyPattern;

public class JPEGCompressor implements Compressor{

    @Override
    public void compress() {
        System.out.println("Compressed using jpeg");
    }
}
