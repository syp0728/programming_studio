package org.example;

public class GenAI {
    // TODO: 아래 항목에 맞게 멤버변수 선언
    // AI 이름 (String)
    private String name;
    // 개발회사 (String)
    private String company;
    // 출시연도 (int)
    private int year;
    // 에이전트 종류 (char) - B, C, I, R, S
    private char category;
    // 구독가격 (double)
    private double price;
    // 생성일자 (String)
    private String createYear;

    // TODO: 기본 생성자 작성


    // TODO: 모든 필드를 매개변수로 받는 생성자 작성
    public GenAI(String name, String company, int year, char category, double price, String createYear) {
        this.name = name;
        this.company = company;
        this.year = year;
        this.category = category;
        this.price = price;
        this.createYear = createYear;
    }

    // TODO: getter / setter 작성
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getCompany() {
        return company;
    }

    public void setCompany(String company) {
        this.company = company;
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }

    public char getCategory() {
        return category;
    }

    public void setCategory(char category) {
        this.category = category;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public String getCreateYear() {
        return createYear;
    }

    public void setCreateYear(String createYear) {
        this.createYear = createYear;
    }

    // TODO: agentType 코드를 문자열로 변환하는 메서드 작성
    // Agent Type 코드를 문자열로 변환하는 메서드
    public String getCategoryString() {
        switch (this.category) {
            case 'B':
                return "Chatbot";
            case 'C':
                return "Coding";
            case 'I':
                return "Image";
            case 'R':
                return "Research";
            case 'S':
                return "Slide";
            default:
                return "Unknown";
        }
    }

    @Override
    public String toString() {
        // category 대신 변환된 문자열을 출력하도록 수정 가능
        return String.format("%s\t%s\t%d\t%s\t%.2f\t%s",
                name, company, year, getCategoryString(), price, createYear);
    }
}
