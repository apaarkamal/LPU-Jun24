package DecoratorPattern;

public class Main {
    public static void main(String[] args) {
        storeCreditCardInfo(new EncryptedCloudStream(new CompressedCloudStream(new CloudStream())));
    }

    public static void storeCreditCardInfo(Stream stream){
        stream.write("apaar kamal");
    }
}
