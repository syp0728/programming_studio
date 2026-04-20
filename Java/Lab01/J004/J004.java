// 좌표 2개를 입력받은 후 좌표 간 거리 계산
import java.util.Scanner; 

class J004{

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        double x1 = s.nextDouble();
        double y1 = s.nextDouble();
        double x2 = s.nextDouble();
        double y2 = s.nextDouble();

        double distance = Math.sqrt(Math.pow(x2-x1, 2) + Math.pow(y2-y1, 2));

        System.out.printf("%.1f\n", distance);        
    }
}