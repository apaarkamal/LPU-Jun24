package MementoPattern;

public class EditorState {
    public EditorState(String content) {
        this.content = content;
    }

    public String getContent() {
        return content;
    }

    private final String content;
}
