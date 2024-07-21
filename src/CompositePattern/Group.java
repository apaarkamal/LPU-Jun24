package CompositePattern;

import java.util.ArrayList;
import java.util.List;

public class Group implements Component {
    private List<Component> components = new ArrayList<>();

    public void add(Component component){
        components.add(component);
    }

    @Override
    public void render(){
        for(var component : components){
           component.render();
        }
    }

    @Override
    public void move() {
        for(var component : components){
            component.move();
        }
    }
}
