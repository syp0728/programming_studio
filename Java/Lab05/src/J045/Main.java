package J045;

import J045.model.MakePWJ045;

public class Main {
    public static void main(String[] args) {
        // 객체 생성 - MakePWJ045 클래스의 인스턴스 생성
        MakePWJ045 pw = new MakePWJ045();

        // 메소드 호출 - 알파벳 3자리와 숫자 6자리가 조합된 코드 생성 요청
        pw.makeCode(3, 6);
    }
}