package J035;
import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);

        String input = s.nextLine();
        int sum = 0;

        String year = input.substring(0, 4);
        for(int i=0; i<4; i++){
            sum += year.charAt(i) - '0';
        }

        String month = input.substring(4, 6);
        sum += Integer.parseInt(month);

        String day = input.substring(6, 8);
        sum += Integer.parseInt(day);

        System.out.printf("%d\n", sum);

    }
}