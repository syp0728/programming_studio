package J025; 
import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int[] monthdays = {31, 28, 31, 30 , 31, 30, 31, 31, 30, 31, 30, 31};
        int month = s.nextInt();
        int day = s.nextInt();
        int day_count = 0; 

        if (month < 1 || month > 12 || day < 1 || day > monthdays[month - 1]) {
            System.out.print("Wrong date!\n");
            return; 
        }        

        for(int i=1; i<month; i++){
            day_count += monthdays[i];
        }

        day_count = day_count + day;
        
        System.out.printf("%d\n", day_count);
    }
}