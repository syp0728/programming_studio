#include <iostream>

using namespace std; 

struct st_score{
    int kor, eng, math;     // 국어점수, 영어점수, 수학점수
    int total;              // 총점
    double average;         // 평균점수
};

int main() {
    st_score score;

    cin >> score.kor >> score.eng >> score.math; 

    score.total = score.kor + score.eng + score.math; 
    score.average = (double)score.total / 3.0;

    printf("%d %.1f\n", score.total, score.average);

    if(score.kor >= 70){
        cout << "Korean - Pass" << endl;
    }else{
        cout << "Korean - Fail" << endl;
    }

    if(score.eng >= 70){
        cout << "English - Pass" << endl;
    }else{
        cout << "English - Fail" << endl;
    }

    if(score.math >= 70){
        cout << "Math - Pass" << endl;
    }else{
        cout << "Math - Fail" << endl;
    }


    return 0;

}