package J045.model;

import java.util.*;

// 클래스 상속 - 기존 MakePW 클래스를 상속받아 기능을 확장함
public class MakePWJ045 extends MakePW {

    // 멤버 변수 - 랜덤 숫자 생성을 위한 객체
    Random rand = new Random();

    // 멤버 메소드 - 알파벳과 숫자가 조합된 코드를 생성하고 출력
    public void makeCode(int length1, int length2) {
        StringBuilder password = new StringBuilder();
        String alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        // length1만큼 랜덤 대문자 알파벳 생성
        for(int i=0; i<length1; i++){
            password.append(alpha.charAt(rand.nextInt(alpha.length())));
        }

        // length2만큼 랜덤 숫자 생성
        for(int i=0; i<length2; i++){
            // 첫 번째 숫자는 0이 오지 않도록 1~9 사이로 설정
            if(i == 0) password.append(rand.nextInt(9) + 1);
                // 그 이후는 0~9 사이의 숫자 생성
            else password.append(rand.nextInt(10));
        }

        // 최종 생성된 코드 출력
        System.out.println(password.toString());
    }
}