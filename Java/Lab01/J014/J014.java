// 연봉을 입력받아 소득세 계산
import java.util.Scanner;

class J014{

    public static void main(String[] args){

        Scanner s = new Scanner(System.in);
        int income = s.nextInt();
        double tax;

        if(income < 10000000) tax = income * 0.095;
        else if(income < 40000000) tax = income * 0.19;
        else if(income < 80000000) tax = income * 0.28;
        else tax = income * 0.37;

        System.out.printf("%d\n", (int)tax);


    }
}