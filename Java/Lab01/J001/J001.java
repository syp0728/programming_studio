// 키와 몸무게로 비만도 계산
import java.util.Scanner; 

class J001 {

    public static void main(String[] a){

        // 입력
        Scanner s = new Scanner(System.in);
        int height = s.nextInt();
        int weight = s.nextInt();

        // 계산
        double bmi = ((double)weight * 10000) / ((double)height * height);
        
        // 출력
        System.out.printf("%.1f\n", bmi);
    }
}