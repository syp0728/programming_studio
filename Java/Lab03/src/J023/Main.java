package J023;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        
        int count = s.nextInt(); 
        
        int[] list = new int[count];
        int totalsum = 0;

        for (int i = 0; i < count; i++) {
            list[i] = s.nextInt();
            totalsum += list[i];
        }

        double average = (double)totalsum / count;

        System.out.println(totalsum);
        System.out.printf("%.1f\n", average);
        
    }
}