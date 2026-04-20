package J062.model;

// 도서명, 저자, 카테고리, 가격, 출간년도
public class Book {
    private String title;
    private String author;
    private String category;
    private int price;
    private int year;

    // 도서명만으로 생성된 생성자
    public Book(String title) {
        this.title = title;
    }

    // 모든 도서 정보를 포함하여 생성한 생성자
    public Book(String title, String author, String category, int price, int year) {
        this.title = title;
        this.author = author;
        this.category = category;
        this.price = price;
        this.year = year;
    }

    // Getter & Setter
    public String getTitle() { return title; }
    public void setTitle(String title) { this.title = title; }

    public String getAuthor() { return author; }
    public void setAuthor(String author) { this.author = author; }

    public String getCategory() { return category; }
    public void setCategory(String category) { this.category = category; }

    public int getPrice() { return price; }
    public void setPrice(int price) { this.price = price; }

    public int getYear() { return year; }
    public void setYear(int year) { this.year = year; }

    // 멤버 내용을 문자열로 리턴
    @Override
    public String toString() { return String.format("[Title: %s\t| Author: %s\t| Category: %s\t| Price: %d\t| Year: %d]", title, author, category, price, year);}
}
