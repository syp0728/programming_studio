package J043;

import J043.model.Lotto;

public class Main {
    public static void main(String[] args) {
        // 로또 번호 객체를 하나 만든다.
        Lotto lotto = new Lotto();

        // 초기에 생성된 로또 번호를 출력한다.
        lotto.printNumbers();

        // 사용자에게 새로 로또 번호를 입력받아 출력한다.
        lotto.remake();
        lotto.printNumbers();

        // 금주의 로또 번호 6개를 입력받아, 일치개수를 찾는다.
        // 금주 번호를 입력받기 위해 별도의 객체 생성
        Lotto winningNumbers = new Lotto();
        winningNumbers.remake();

        // 내 번호 와 금주 번호 대조
        int result = lotto.checkLotto(winningNumbers.getNumbers());

        // 당첨 여부(일치 개수) 출력
        System.out.println(result);
    }
}