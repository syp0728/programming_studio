package J041.model;

//import java.util.Array;
//import java.util.Random;

import java.util.*;

public class Lotto {
    // 멤버변수
    private int[] numbers;
    private Random random = new Random();

    // 생성자
    public Lotto() {
        numbers = new int[6];
        remakeAuto();
    }

    // 멤버메소드 - getter & setter
    // 출력함수
    public void printNumbers() {
        Arrays.sort(numbers);
        for (int i = 0; i < numbers.length; i++) {
            System.out.print(numbers[i] + " ");
        }
        System.out.println();
    }

    // 로또 번호 생성하는 함수
    public void remakeAuto() {
        // 로또 번호 : 1 ~45 - 1~ 44 > 1~ 45
        // 로또 번호는 6개를 생성
        for (int i = 0; i < numbers.length; i++) {
            numbers[i] = random.nextInt(45) + 1;

            // 중복은 제거해야 함
            for (int j = 0; j < i; j++) {
                if (numbers[j] == numbers[i]) {
                    i--;
                    break;
                }
            }
        }
    }
}