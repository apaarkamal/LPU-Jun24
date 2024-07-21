package SingletonPattern;

import java.util.HashMap;
import java.util.Map;
import java.util.Objects;

public class ConfigManager {
    private Map<String, Object> setting = new HashMap<>();
    private static ConfigManager instance = new ConfigManager();

    private ConfigManager() {}

    public static ConfigManager getInstance(){
        return instance;
    }

    public void setSetting(Map<String, Object> setting) {
        this.setting = setting;
    }

    public Object get(String name){
        return setting.get(name);
    }

    public void set(String name, Object object){
        setting.put(name, object);
    }
}
