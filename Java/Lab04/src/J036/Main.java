package J036;
import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);

        String input = s.nextLine().toLowerCase();
        StringBuilder filtered = new StringBuilder();

        for(int i=0; i<input.length(); i++){
            char ch = input.charAt(i);
            if(ch >= 'a' && ch <= 'z') filtered.append(ch);
        }

        String target = filtered.toString();
        boolean isPalindrome = true;

        for(int i=0; i<(target.length() / 2); i++){
            if(target.charAt(i) != target.charAt(target.length() - 1 - i)){
                isPalindrome = false;
                break;
            }
        }

        if(isPalindrome){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
    }
}