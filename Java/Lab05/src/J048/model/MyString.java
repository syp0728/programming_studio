package J048.model;
import java.util.*;

public class MyString {
    // 멤버 메소드 - 두 문자열을 비교하여 사전순으로 앞서는 쪽의 번호(1 또는 2)를 반환
    public static int whichFirst(String str1, String str2) {

        // 대소문자 구분 없이 비교하기 위해 모두 소문자로 변환
        String s1 = str1.toLowerCase();
        String s2 = str2.toLowerCase();

        // 두 문자열 중 짧은 쪽의 길이를 기준으로 반복문 설정
        int minLength = Math.min(s1.length(), s2.length());

        for (int i = 0; i < minLength; i++) {
            char c1 = s1.charAt(i);
            char c2 = s2.charAt(i);

            // 각 자리의 문자를 비교하여 순서 결정
            if (c1 < c2) {
                return 1; // str1이 앞
            } else if (c1 > c2) {
                return 2; // str2가 앞
            }
        }

        // 앞부분이 모두 같다면 길이가 짧은 문자열이 사전순으로 앞섬
        if (s1.length() <= s2.length()) {
            return 1;
        } else {
            return 2;
        }
    }


    // 멤버 메소드 - StringBuilder를 사용하여 공백과 탭을 수동으로 제거
    public static String removeSpaces(String str) {
        // 수정 가능한 문자열 객체 생성
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);

            // 공백(' ')이나 탭('\t')이 아닐 때만 StringBuilder에 추가
            if (ch != ' ' && ch != '\t') {
                sb.append(ch);
            }
        }
        // 완성된 StringBuilder를 다시 String으로 변환하여 리턴
        return sb.toString();
    }


    // 멤버 메소드 - 파라미터로 받은 문자열에서 가장 긴 단어를 찾아서 리턴한다.
    // 단, 동일한 길이의 단어인 경우 먼저 나온 단어를 리턴함
    public static String findLongestWord(String str) {
        // 공백을 기준으로 문자열을 분리하여 배열에 저장
        String[] words = str.split(" ");
        String longest = "";

        for (String word : words) {
            // 현재 저장된 단어보다 더 긴 단어가 나타나면 업데이트
            if (word.length() > longest.length()) {
                longest = word;
            }
        }
        return longest;
    }
}











