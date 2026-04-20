// 날짜를 입력받아 1년 중 몇번째 날인지 계산
import java.util.Scanner; 

class J005{

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        int month = s.nextInt();
        int day = s.nextInt();
        int day_count = 0; 

        int[] month_day = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        for(int i=1; i<month; i++){
            day_count += month_day[i];
        }

        day_count = day_count + day;
        
        System.out.printf("%d\n", day_count);        
    }
}