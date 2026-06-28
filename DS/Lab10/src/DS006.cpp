#include <iostream>

using namespace std;

struct Major
{
    string subject;    // 과목명 (문자열)
    int credit;        // 학점수 (1 ~ 4)
    int score;         // 취득점수 (0 ~ 100)
    double gradePoint; // 평점 (4.5, 4.0 등)
    string grade;      // 등급 (A+ ~ F)
};

int main()
{
    Major m[3];
    int totalCredit = 0;
    double totalGrade = 0;

    for (int i = 0; i < 3; i++)
    {
        cin >> m[i].subject >> m[i].credit >> m[i].score;

        if (m[i].score >= 95)
        {
            m[i].grade = "A+";
            m[i].gradePoint = 4.5;
        }
        else if (m[i].score >= 90)
        {
            m[i].grade = "A0";
            m[i].gradePoint = 4.0;
        }
        else if (m[i].score >= 85)
        {
            m[i].grade = "B+";
            m[i].gradePoint = 3.5;
        }
        else if (m[i].score >= 80)
        {
            m[i].grade = "B0";
            m[i].gradePoint = 3.0;
        }
        else if (m[i].score >= 75)
        {
            m[i].grade = "C+";
            m[i].gradePoint = 2.5;
        }
        else if (m[i].score >= 70)
        {
            m[i].grade = "C0";
            m[i].gradePoint = 2.0;
        }
        else
        {
            m[i].grade = "F";
            m[i].gradePoint = 0.0;
        }

        totalCredit += m[i].credit;
        totalGrade += (m[i].credit * m[i].gradePoint);
    }

    cout << "==============================" << endl;
    double GPA = totalGrade / totalCredit;

    for(int i=0; i<3; i++)
    {
        printf("%s(%d)\t%s\t%.1f\n", m[i].subject.c_str(), m[i].credit, m[i].grade.c_str(), m[i].gradePoint);
    }

    printf("Total Credits %d, GPA %.2f\n", totalCredit, GPA);

    return 0;
}