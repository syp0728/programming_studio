package J061.model;

// 단어 정보를 담고 있는 Word 클래스
public class Word {
    private String english;
    private String korean;
    private int level;

    // 모든 멤버 데이터를 파라미터로 받아서 생성하는 생성자
    public Word(String english, String korean, int level){
        this.english = english;
        this.korean = korean;
        this.level = level;
    }

    // Getter & Setter
    public String getEnglish() {
        return english;
    }
    public void setEnglish(String english) {
        this.english = english;
    }

    public String getKorean() {
        return korean;
    }
    public void setKorean(String korean) {
        this.korean = korean;
    }

    public int getLevel() {
        return level;
    }
    public void setLevel(int level) {
        this.level = level;
    }


    // 멤버 내용을 문자열로 리턴
    @Override
    public String toString() {
        return String.format("[%d] %s : %s", level, english, korean);
    }
}
