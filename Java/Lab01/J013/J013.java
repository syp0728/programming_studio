// 국, 영, 수 과목 점수를 입력받아 총점과 평균을 계산하고, 등급 판정
import java.util.Scanner;

class J013{

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        int kor = s.nextInt(); // 국어점수
        int eng = s.nextInt(); // 영어점수
        int math = s.nextInt(); // 수학점수

        int total = kor + eng + math; // 총점
        double average = (kor + eng + math) / 3.0; // 평균점수

        int[] score = {kor, eng, math};
        String[] subject = {"Korean", "English", "Math"};
        System.out.printf("%d %.1f\n", total, average);

        for(int i=0; i<3; i++){
            String result = (score[i] >= 70) ? "Pass" : "Fail";

            System.out.printf("%s - %s\n", subject[i], result);
        }
    }
}