package J032; 
import java.util.Scanner; 

public class Main{
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        Main main = new Main();

        String str = s.nextLine();
        String reverse = "";

        reverse = main.getReverse(str);

        System.out.printf(reverse + "\n");

    }

    public String getReverse(String str) {
        String reverse = "";

        for(int i=str.length() - 1; i>=0; i--){
            reverse = reverse + str.charAt(i);
        }
        return reverse;
    }
}

