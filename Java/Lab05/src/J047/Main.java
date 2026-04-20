package J047;

import J047.model.MyString;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        // 공백을 포함해야 하므로 nextLine() 사용
        String input = s.nextLine();

        // 메소드 호출 - 수동으로 공백을 제거하는 static 메소드 실행
        String result = MyString.removeSpaces(input);
        System.out.println(result);

    }
}