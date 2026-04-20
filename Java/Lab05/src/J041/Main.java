package J041;

import J041.model.Lotto;

public class Main {
    public static void main(String[] args) {

        // Lotto 객체 생성
        Lotto lotto = new Lotto();

        // 현재 로또 번호 출력
        lotto.printNumbers();

        // 로또 번호 재생성
        lotto.remakeAuto();

        // 새로 바뀐 로또 번호 출력
        lotto.printNumbers();
    }
}