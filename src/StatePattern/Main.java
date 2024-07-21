package StatePattern;

public class Main {
    public static void main(String[] args) {
        Canvas canvas = new Canvas();
        canvas.setCurrentTool(new EraserTool());
        canvas.work();

        canvas.setCurrentTool(new SelectionTool());
        canvas.work();

        canvas.setCurrentTool(new BrushTool());
        canvas.work();
    }
}
