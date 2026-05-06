package src.model;

public class ServiceItem {
    // 멤버 변수
    private String name;
    private int price;
    private String date;
    private int person;
    private String category;


    // 모든 Service 정보를 포함하여 생성한 생성자
    public ServiceItem(String name, int price, String date, int person, String category) {
        this.name = name;
        this.price = price;
        this.date = date;
        this.person = person;
        this.category = category;
    }

    // Getter & Setter
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }

    public int getPrice() {
        return price;
    }
    public void setPrice(int price) {
        this.price = price;
    }

    public String getDate() {
        return date;
    }
    public void setDate(String date) {
        this.date = date;
    }

    public int getPerson() {
        return person;
    }
    public void setPerson(int person) {
        this.person = person;
    }

    public String getCategory() {
        return category;
    }
    public void setCategory(String category) {
        this.category = category;
    }


    // 파일 저장용 데이터 포맷
    // PrintWriter로 파일 저장 시 불러오기 편하도록 "|" 사용
    @Override
    public String toString() {
        return String.format("%-12s | %10d | %-12s | %-8d | %s",
                name, price, date, person, category);
    }
}