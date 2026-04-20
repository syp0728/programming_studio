// 섭씨 온도를 화씨 온도로 변환
import java.util.Scanner; 

class J002{

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        double c_degree = s.nextDouble();

        double f_degree = c_degree * 1.8 + 32;

        System.out.printf("%.1f\n", f_degree);        
    }
}