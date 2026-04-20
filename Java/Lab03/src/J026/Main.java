package J026;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int count = s.nextInt(); 

        int[] list = new int[count];
        
        int max_num = 0;   
        int min_num = 100; 

        for (int i = 0; i < count; i++) {
            list[i] = s.nextInt();
        }

        for (int i = 0; i < list.length; i++) {
            if (list[i] > max_num) {
                max_num = list[i];
            }
            
            if (list[i] < min_num) {
                min_num = list[i];
            }
        }

        System.out.printf("가장 큰 수 %d\n", max_num);
        System.out.printf("가장 작은 수 %d\n", min_num);
        
    }
}