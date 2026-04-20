// 아파트 평형 계산 및 종류 판정
import java.util.Scanner;

class J012{

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        double m2_area = s.nextDouble();
        double pyung_area = m2_area / 3.305;
        String size;

        if(pyung_area < 15) size = "small";
        else if(pyung_area < 30) size = "normal";
        else if(pyung_area < 50) size = "large";
        else size = "huge";

        System.out.printf("%.1f\n%s\n", pyung_area, size);
    }
}