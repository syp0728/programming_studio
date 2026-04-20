package J030;
import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);

        int[] number = new int[10];
        int count = 0;

//        while(count < 10){
//            System.out.printf("Enter #%d number > ", count + 1);
//            int input = s.nextInt();
//
//            if(input < 1 || input > 100){
//                System.out.println("Invalid! 1~100 only. ");
//                continue;
//            }
//
//            boolean isDuplicated = false;
//
//            for(int i=0; i<count; i++){
//                if(number[i] == input){
//                    isDuplicated = true;
//                    break;
//                }
//            }
//
//            if(!isDuplicated) {
//                number[count] = input;
//                count++;
//            }else{
//                System.out.println("Duplicated! Retry. ");
//            }
//        }


        for(int i=0; i<10; i++){
            System.out.printf("Enter #%d number > ", i+1);
            int input = s.nextInt();

            if(input < 1 || input > 100){
                System.out.println("Invalid number!. 1~100 only.");
                i--;
                continue;
            }

            boolean isDuplicated = false;
            for(int j=0; j<i; j++){
                if(number[j] == input){
                    isDuplicated = true;
                    break;
                }
            }

            if(isDuplicated){
                System.out.println("Duplicated! Retry.");
                i--;
            }else{
                number[i] = input;
            }
        }


    }
}