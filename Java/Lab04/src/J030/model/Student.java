package J030.model;

public class Student {
    private String name;
    private int[] mySheet;
    private int grade;

    public Student(String name, int[] sheet) {
        this.name = name;
        this.mySheet = sheet;
    }

    public void grading(int[] answer) {
        int count = 0;
        for (int j = 0; j < 10; j++) {
            if (this.mySheet[j] == answer[j]) {
                count++;
            }
        }

        if (count > 8) this.grade = 1;
        else if (count > 6) this.grade = 2;
        else this.grade = 3;
    }

    public String getName() { return name; }
    public int getGrade() { return grade; }
}