package J024;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int[] numbers = new int[10];
        int first = -1;           
        int second = -1;          
        int second_max_index = 0;  

        for (int i = 0; i < 10; i++) {
            numbers[i] = s.nextInt();
        }

        for (int i = 0; i < 10; i++) {
            if (numbers[i] > first) {
                second = first;           
                second_max_index = i;      
            }
        }

        first = numbers[0];
        second = -1;
        int first_index = 0;

        for (int i = 1; i < 10; i++) {
            if (numbers[i] > first) {
                second = first;
                second_max_index = first_index;
                first = numbers[i];
                first_index = i;
            } else if (numbers[i] > second && numbers[i] < first) {
                second = numbers[i];
                second_max_index = i;
            }
        }

        System.out.printf("[%d] %d\n", second_max_index + 1, second);
    }
}