package J052.model;

import java.util.Scanner;

public class Score {
    // 멤버 변수
    int count;                      // 학생 인원 수
    int[][] jumsu;                 // 점수를 저장하고 있는 2차원 배열
    int[] sum_student;             // 학생별 총점
    double[] average_student;      // 학생별 평균

    // 생성자
    public Score(int count) {
        this.count = count;
        this.jumsu = new int[count][3];
        this.sum_student = new int[count];
        this.average_student = new double[count];
    }

    // 멤버 메소드
    public void getScore() {
        Scanner s = new Scanner(System.in);
        for (int i = 0; i < count; i++) {
            System.out.printf((i + 1) + ". Korean, English, Math Score : ");
            jumsu[i][0] = s.nextInt(); // 국어
            jumsu[i][1] = s.nextInt(); // 영어
            jumsu[i][2] = s.nextInt(); // 수학

            // 학생별 총점과 평균 계산
            sum_student[i] = jumsu[i][0] + jumsu[i][1] + jumsu[i][2];
            average_student[i] = sum_student[i] / 3.0;
        }
    }

    // 멤버 메소드
    public void printScore() {
        // 각 학생별 정보 출력
        System.out.println("\n[Student]");
        System.out.println("Number\tKorean\tEnglish\tMath\tTotal\tAverage\tGrade");
        for (int i = 0; i < count; i++) {
            System.out.printf("%d\t%d\t%d\t%d\t%d\t%.1f\t%s\n",
                    (i + 1), jumsu[i][0], jumsu[i][1], jumsu[i][2],
                    sum_student[i], average_student[i], getGrade(average_student[i]));
        }

        // 각 과목별 총점과 평균 점수 출력
        System.out.println("\n[Subject]");
        String[] subjects = {"Korean", "English", "Math"};
        for (int j = 0; j < 3; j++) {
            int subSum = 0;
            for (int i = 0; i < count; i++) {
                subSum += jumsu[i][j];
            }
            System.out.printf("%s total score: %d, average score: %.1f\n",
                    subjects[j], subSum, (double)subSum / count);
        }
    }

    // 등급 결정 메소드
    private String getGrade(double avg) {
        if (avg >= 90) return "A";
        else if (avg >= 80) return "B";
        else if (avg >= 70) return "C";
        else if (avg >= 60) return "D";
        else return "F";
    }
}