package SingletonPattern;

public class Main {
    public static void main(String[] args) {
        ConfigManager manager = ConfigManager.getInstance();
        manager.set("Apaar", "kamal");
        System.out.println(manager.get("Apaar"));


        //        .........
        ConfigManager other = ConfigManager.getInstance();
        System.out.println(other.get("Apaar"));
    }
}
