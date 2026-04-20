package J063.model;

// 할 일 정보를 담고 있는 Todo 클래스
public class Todo {
    private String title;
    private String content;
    private String date;
    private String category;

    // 할 일 제목만으로 생성된 생성자
    public Todo(String title){
        this.title = title;
    }

    // 모든 할 일 정보를 포함하여 생성항 생성자
    public Todo(String title, String content, String date, String category){
        this.title = title;
        this.content = content;
        this.date = date;
        this.category = category;
    }

    // Getter & Setter
    public String getTitle() { return title; }
    public void setTitle(String title) { this.title = title; }

    public String getContent() { return content; }
    public void setContent(String content) { this.content = content; }

    public String getDate() { return date; }
    public void setDate(String date) { this.date = date; }

    public String getCategory() { return category; }
    public void setCategory(String category) { this.category = category; }

    // 문자 내용을 문자열로 리턴
    @Override
    public String toString() { return String.format("[Title: %s\t| Category: %s\t| Date: %s\t| Content: %s\t]", title, category, date, content);}
}