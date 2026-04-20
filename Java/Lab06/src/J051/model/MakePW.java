package J051.model;

import java.util.*;

public class MakePW {
    // 멤버 변수 - 랜덤 객체 및 비밀번호에 사용될 문자셋 정의
    Random rand = new Random();
    final static String CHARSET = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

    // 생성자 - 기본 생성자
    public MakePW() {
    }


    // 멤버 메소드 - 오버로딩: 지정된 길이(length)의 암호를 지정된 개수(amount)만큼 생성
    public void make(int length, int amount) {
        // 입력받은 개수(amount)만큼 반복문 실행
        for (int j = 0; j < amount; j++) {
            StringBuilder password = new StringBuilder();

            // 지정된 길이만큼 랜덤 문자 조합
            for (int i = 0; i < length; i++) {
                password.append(CHARSET.charAt(rand.nextInt(CHARSET.length())));
            }

            // 생성된 각 암호를 출력
            System.out.println(password.toString());
        }
    }
}