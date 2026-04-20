package J055;

import J055.model.BMICalculator;

public class Main {
    public static void main(String[] args) {
        // 객체 생성
        BMICalculator calc = new BMICalculator();

        // 이름, 신장, 체중 입력
        calc.getHW();

        // 결과 출력
        calc.printBMI();
    }
}