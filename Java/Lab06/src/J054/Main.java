package J054;

import J054.model.Score;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Score score = new Score(5);

        // 5명의 점수를 입력받고 계산
        score.getScore();

        // 특정 학생의 점수만 출력
        Scanner s = new Scanner(System.in);
        System.out.print("\nEnter the number : ");
        int searchNum = s.nextInt();

        // 특정 학생의 점수, 총점, 평균만 출력
        score.printScore(searchNum);

        // 과목별 분석 출력
        System.out.println("\n[Subject Analysis]");
        score.printScore(0, "Korean");
        score.printScore(1, "English");
        score.printScore(2, "Math");
    }
}