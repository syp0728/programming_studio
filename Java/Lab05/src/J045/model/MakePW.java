package J045.model;

import java.util.*;

public class MakePW {
    // 멤버 변수 - 랜덤 객체 및 비밀번호에 사용될 문자셋 정의
    Random rand = new Random();
    final static String CHARSET = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

    // 생성자 - 기본 생성자
    public MakePW() {
    }

    // 멤버 메소드 - 지정된 길이에 맞춰 랜덤 비밀번호를 생성하고 출력
    public void make(int length) {
        StringBuilder password = new StringBuilder();
//        String charSet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";


        for (int i = 0; i < length; i++) {
//            int pos = rand.nextInt(charSet.length()); // 4
//            char c = charSet.chrAt(pos);
//            password.append(c);

            // CHARSET에서 랜덤하게 문자 하나를 선택해 추가
            password.append(CHARSET.charAt(rand.nextInt(CHARSET.length())));
        }
        // 생성된 비밀번호 출력
        System.out.println(password.toString());
    }
}