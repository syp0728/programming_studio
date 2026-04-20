package J054.model;

import java.util.Scanner;

public class Score {
    // 멤버 변수
    int count;                      // 학생 인원 수
    int[][] jumsu;                 // 점수를 저장하고 있는 2차원 배열
    int[] sum_student;             // 학생별 총점
    double[] average_student;      // 학생별 평균

    protected int[] sum_class = new int[3];
    protected double[] average_class = new double[3];

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

        // 과목별 총점 및 평균 계산
        for (int j = 0; j < 3; j++) {
            int subSum = 0;
            for (int i = 0; i < count; i++) {
                subSum += jumsu[i][j];
            }
            sum_class[j] = subSum;
            average_class[j] = (double) subSum / count;
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
//
//
    // 메소드 오버로딩 - 특정 학생의 점수, 총점, 평균만 출력
    public void printScore(int num) {
        // 배열 인덱스는 0부터 시작하므로 num-1 사용
        int idx = num - 1;

        if (idx >= 0 && idx < count) {
            System.out.println("\n[No." + num + " Student]");
            System.out.println("Korean : " + jumsu[idx][0]);
            System.out.println("English : " + jumsu[idx][1]);
            System.out.println("Math : " + jumsu[idx][2]);
            System.out.println("Total : " + sum_student[idx]);
            System.out.printf("Average: %.1f\n", average_student[idx]);
        } else {
            System.out.println("Invalid Number");
        }
    }

    //메소드 오버로딩 - 특정 과목의 총점과 평균 출력
    public void printScore(int num, String classname) {
        // num은 과목 인덱스 (0:국어, 1:영어, 2:수학)
        if (num >= 0 && num < 3) {
            System.out.printf("[%s] Total: %d, Average: %.1f\n",
                    classname, sum_class[num], average_class[num]);
        }
    }
}