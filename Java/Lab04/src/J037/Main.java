package J037;
import java.util.Scanner;
import java.util.Arrays;

public class Main{
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);

        String s1 = s.nextLine();
        String s2 = s.nextLine();

        StringBuilder f1 = new StringBuilder();
        StringBuilder f2 = new StringBuilder();

        for(int i=0; i<s1.length(); i++){
            char ch = s1.charAt(i);
            if(ch >= 'a' && ch <= 'z') f1.append(ch);
        }

        for(int i=0; i<s2.length(); i++){
            char ch = s2.charAt(i);
            if(ch >= 'a' && ch <= 'z') f2.append(ch);
        }


        if(isAnagram(f1.toString(), f2.toString())){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
    }

    public static boolean isAnagram(String str1, String str2){
        if(str1.length() != str2.length()) return false;

        char[] charArray1 = str1.toCharArray();
        char[] charArray2 = str2.toCharArray();

        Arrays.sort(charArray1);
        Arrays.sort(charArray2);

        return Arrays.equlas(charArray1, charArray2)l;
    }
}