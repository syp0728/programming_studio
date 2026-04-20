// 아파트의 제곱미터 수치를 평형으로 바꾸기
import java.util.Scanner; 

class J003{

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        double m2_area = s.nextDouble();

        double pyung_area = m2_area / 3.305;

        System.out.printf("%.1f\n", pyung_area);        
    }
}