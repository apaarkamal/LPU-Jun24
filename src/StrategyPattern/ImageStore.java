package StrategyPattern;

public class ImageStore {
    public void store(Compressor compression, Filter filter){
        compression.compress();
        filter.apply();
    }
}
