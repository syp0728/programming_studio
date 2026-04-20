package J053;

import J053.model.Score;

public class Main {
    public static void main(String[] args) {
        // Score 객체 생성
        Score score = new Score(5);

        // 5명의 점수를 입력받고 계산
        score.getScore();

        // 5명의 점수, 총점, 평균 출력
        score.printScore();
    }
}