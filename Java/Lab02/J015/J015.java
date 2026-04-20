// 3개의 수 중 최댓값과 최솟값 구하기
import java.util.Scanner;

class J015{

    public static void main(String[] args){
        Scanner s = new Scanner(System.in);

        int num1 = s.nextInt();
        int num2 = s.nextInt();
        int num3 = s.nextInt();

        int max_num = num1;
        int min_num = num1;

        if(num2 > max_num) max_num = num2;
        if(num3 > max_num) max_num = num3;

        if(num2 < min_num) min_num = num2;
        if(num3 < min_num) min_num = num3;

        System.out.printf("%d %d\n", max_num, min_num);

    }
}