package J055.model;

import java.util.Scanner;

public class BMICalculator {
    // 멤버 변수
    int height, weight;     // 신장(cm), 체중(kg)
    double bmi;             // 비만도
    int level;              // 비만도 등급 (1~4)
    String name;            // 이름

    // 생성자
    public BMICalculator() {
    }

    // 비만도와 등급을 계산
    public void getHW() {
        Scanner s = new Scanner(System.in);

        System.out.print("Name : ");
        this.name = s.nextLine();
        System.out.print("Height : ");
        this.height = s.nextInt();
        System.out.print("Weight : ");
        this.weight = s.nextInt();

        // BMI 계산
        double heightMeter = height / 100.0;
        this.bmi = weight / (heightMeter * heightMeter);

        // 비만등급 판정 (1~4)
        if (bmi < 18.5) level = 1;
        else if (bmi < 25) level = 2;
        else if (bmi < 30) level = 3;
        else level = 4;
    }

    // 등급 숫자를 문자열로 변환하는 내부 메소드
    private String getLevelString() {
        switch (level) {
            case 1: return "Underweight";
            case 2: return "Healthy Weight";
            case 3: return "Overweight";
            case 4: return "Obesity";
            default: return "Unknown";
        }
    }

    // 결과 출력
    public void printBMI() {
        System.out.println("\n------------------------------");
        System.out.println("Name : " + name);
        System.out.println("Height : " + height + "cm");
        System.out.println("Weight : " + weight + "kg");
        System.out.printf("BMI: %.2f\n", bmi);
        System.out.println("BMI Level : " + getLevelString() + " (" + level + ")");
        System.out.println("------------------------------");
    }
}