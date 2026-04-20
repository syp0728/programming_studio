package J051;

import J051.model.MakePW;

public class Main {
    public static void main(String[] args) {
        // 객체 생성 - MakePW 클래스의 인스턴스 생성
        MakePW makePW = new MakePW();

        // 메소드 호출 - 10자리 랜덤 비밀번호 생성 요청
        makePW.make(10, 6);
    }
}