package J030;

import J030.model.Student;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        String[] names = {"James", "David", "Simon", "Peter", "Jason"};
        int[] answer = {1, 2, 3, 4, 1, 2, 3, 4, 3, 2};

        Student[] students = new Student[5];

        for (int i = 0; i < 5; i++) {
            int[] oneStudentSheet = new int[10];
            for (int j = 0; j < 10; j++) {
                oneStudentSheet[j] = s.nextInt();
            }

            students[i] = new Student(names[i], oneStudentSheet);

            students[i].grading(answer);
        }

        StringBuilder[] sb = {new StringBuilder(), new StringBuilder(), new StringBuilder()};
        int[] studentCount = new int[3];

        for (int i = 0; i < 5; i++) {
            int idx = students[i].getGrade() - 1;
            sb[idx].append(students[i].getName()).append(" ");
            studentCount[idx]++;
        }

        String[] titles = {"1st", "2nd", "Fail"};
        for (int i = 0; i < 3; i++) {
            System.out.printf("%s : %s(%d)\n", titles[i], sb[i].toString(), studentCount[i]);
        }
    }
}