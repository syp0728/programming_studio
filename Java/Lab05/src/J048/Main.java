package J048;

import J048.model.MyString;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        // 문장 입력받기
        String input = s.nextLine();

        // 메소드 호출 - 가장 긴 단어 찾기
        String longestWord = MyString.findLongestWord(input);

        // 가장 긴 단어와 그 길이를 함께 출력
        if (!longestWord.isEmpty()) {
            System.out.println(longestWord + " " + longestWord.length());
        }
    }
}