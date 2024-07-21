package DecoratorPattern;

public class EncryptedCloudStream implements Stream{
    private Stream stream;

    public EncryptedCloudStream(Stream stream){
        this.stream = stream;
    }

    @Override
    public void write(String data) {
        stream.write(encryptData(data));
    }

    private String encryptData(String data){
        return "qwjkqjkhjw";
    }
}
