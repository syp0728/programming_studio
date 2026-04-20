// 날짜를 입력받아 1년 중 몇번째 날인지 계산
import java.util.Scanner;

class J011{

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        int height = s.nextInt();
        int weight = s.nextInt();

        double bmi = ((double)weight * 10000) / ((double)height * height);

        if(bmi >= 25) System.out.printf("Yes\n");
        else System.out.printf("No\n");

    }
}