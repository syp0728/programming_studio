package J046;

import J046.model.MyString;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        // 입력 - 비교할 두 문자열을 입력받음
        String first = s.nextLine();
        String second = s.nextLine();

        // 메소드 호출 - MyString 클래스의 static 메소드를 사용하여 순서 비교
        int firstIndex = MyString.whichFirst(first, second);

        // 결과값에 따라 사전순으로 앞에 오는 번호와 해당 문자열 출력
        if (firstIndex == 1) {
            System.out.println("1 " + first);
        } else {
            System.out.println("2 " + second);
        }
    }
}