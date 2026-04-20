import java.util.Scanner;


public class Main{
    public static void main(String[] args){
        // Main main = new Main();
        // main.j029();

        new Main().j029();
    }

    public void j029() {
        Scanner s = new Scanner(System.in);

        int[] number = new int[10];
        int count = 0;

        // 1. for 반복문 사용
        // for (int i = 0; i < number.length; i++) {

        //     System.out.printf("Enter #%d number > ", i+1);
        //     number[i] = s.nextInt();
            
        //     for(int j=0; j<i; j++){
        //         if(number[i] == number[j]){
        //             System.out.printf("Duplicated! Retry.\n");
        //             i--;
        //         } 
        //     }
        // }

        // 2. while 반복문 사용
        while (count < 10) {
            System.out.printf("Enter #%d number > ", count + 1);
            number[count] = s.nextInt(); 

            count++;
            
            for (int j = 0; j < count - 1; j++) {
                if (number[count - 1] == number[j]) {
                    System.out.printf("Duplicated! Retry.\n");
                    count--;
                    break;
                }
            }
        }


        System.out.printf("Numbers - ");

        for(int k=0; k<number.length; k++){
            System.out.printf("%d ", number[k]);
        }
        System.out.printf("\n");

    }
}