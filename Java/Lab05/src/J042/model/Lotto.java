package J042.model;

//import java.util.Array;
//import java.util.Random;
import java.util.*;

public class Lotto {
    Scanner s = new Scanner(System.in);

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
        // 로또 번호는 6개를 만든다.
        for (int i = 0; i < numbers.length; i++) {
            numbers[i] = random.nextInt(45) + 1;

            // 중복은 제거해야 된다.
            for (int j = 0; j < i; j++) {
                if (numbers[j] == numbers[i]) {
                    i--;
                    break;
                }
            }
        }
    }

    // 사용자에게 로또 번호 새로 입력받기
    public void remake() {
        String line = s.nextLine();          // 한 줄 입력
        String[] arr = line.split(" ");      // 문자열 분리

        int[] input = new int[6];

        for (int i = 0; i < 6; i++) {
            int num = Integer.parseInt(arr[i]);

            // 범위 체크
            if (num < 1 || num > 45) {
                System.out.println("Invalid number!");
                return;
            }

            // 중복 체크
            for (int j = 0; j < i; j++) {
                if (input[j] == num) {
                    System.out.println("Duplicate!");
                    return;
                }
            }

            input[i] = num;
        }

        numbers = input;
    }
}