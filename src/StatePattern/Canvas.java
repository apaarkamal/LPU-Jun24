package StatePattern;

public class Canvas {
    public Tool getCurrentTool() {
        return currentTool;
    }

    public void setCurrentTool(Tool currentTool) {
        this.currentTool = currentTool;
    }

    private Tool currentTool;

    public void work(){
        currentTool.work();
    }

}
