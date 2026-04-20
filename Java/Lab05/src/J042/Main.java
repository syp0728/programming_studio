package J042;

import J042.model.Lotto;

public class Main{
    public static void main(String[] args){
        // Lotto 객체 생성
        Lotto lotto = new Lotto();

        // 현재 로또 번호 출력
        lotto.printNumbers();

        // 로또 번호 재생성
        lotto.remakeAuto();

        // 로또 번호 입력받기
        lotto.remake();
    }
}
