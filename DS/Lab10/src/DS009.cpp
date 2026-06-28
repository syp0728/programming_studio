#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int findRoom(int persons[5]);
void printReport(string mn[10], int mr[10], int mc, string wn[10], int wr[10], int wc);

int main()
{
    string mnames[10];          // names of all male students (max. 10)
    string wnames[10];          // names of all female students (max. 10)
    int mroom[10];              // room numbers assigned all male students
    int wroom[10];              // room numbers assigned all female students
    int person[2][5] = {0};     // number of persons assgined to all rooms (two floors & each five rooms)
    int mcount = 0, wcount = 0; // number of all persons (male, female)
    int menu;

    srand(time(0));
    cout << "===========================================" << endl;
    cout << "생활관 호실 배정 프로그램" << endl;
    cout << "===========================================" << endl;
    while (1)
    {
        cout << "메뉴 : 1.남학생 등록 2.여학생 등록 0.종료 > ";
        cin >> menu;
        if (menu == 0)
            break;
        else if (menu == 1)
        {
            if (mcount >= 10)
            {
                cout << "정원 초과입니다. 등록불가!" << endl;
                continue;
            }
            cout << "학생 이름은? > ";
            cin >> mnames[mcount];
            int roomno = findRoom(person[0]);
            mroom[mcount] = 100 + roomno;
            cout << mnames[mcount] << " 학생 " << mroom[mcount] << "호실 배정되었습니다." << endl;
            mcount++;
        }
        else if (menu == 2)
        {
            if (wcount >= 10)
            {
                cout << "정원 초과입니다. 등록불가!" << endl;
                continue;
            }
            cout << "학생 이름은? > ";
            cin >> wnames[wcount];
            int roomno = findRoom(person[1]);
            wroom[wcount] = 200 + roomno;
            cout << wnames[wcount] << " 학생 " << wroom[wcount] << "호실 배정되었습니다." << endl;
            wcount++;
        }
    }

    cout << "===========================================" << endl;
    cout << "생활관 호실 배정 결과는 다음과 같습니다." << endl;
    cout << "===========================================" << endl;
    printReport(mnames, mroom, mcount, wnames, wroom, wcount);

    return 0;
}

int findRoom(int persons[5])
{
    // 랜덤으로 1~5 사이의 숫자 생성
    // 해당 숫자에 해당하는 방의 인원 수가 2명 이상이면 다시 랜덤 숫자 생성
    // 2명 미만이면 해당 방의 인원 수 증가시키고 방 번호 반환
    int roomno;
    while (1)
    {
        roomno = rand() % 5 + 1; 
        if (persons[roomno - 1] < 2)
        {
            persons[roomno - 1]++;
            break;
        }
    }
    return roomno;
}

void printReport(string mn[10], int mr[10], int mc, string wn[10], int wr[10], int wc)
{
    // 남학생 명단과 여학생 명단 출력
    // 호실별 배정 명단 출력 (101~105호는 남학생, 201~205호는 여학생)      
      
    printf("남학생 명단(%d명)\n", mc);
    for (int i = 0; i < mc; i++)
    {
        cout << i + 1 << ". " << mn[i] << " [" << mr[i] << "호]" << endl;
    }
    cout << endl;

    printf("여학생 명단(%d)\n", wc);
    for (int i = 0; i < wc; i++)
    {
        cout << i + 1 << ". " << wn[i] << " [" << wr[i] << "호]" << endl;
    }

    cout << "\n호실별 배정 명단" << endl;


    for (int i = 101; i <= 105; i++){
        cout << i << "호:";
        for (int j = 0; j < mc; j++){
            if (mr[j] == i){
                cout << " " << mn[j];
            }
        }
        cout << endl;
    }

    for (int i = 201; i <= 205; i++){
        cout << i << "호:";
        for (int j = 0; j < wc; j++){
            if (wr[j] == i){
                cout << " " << wn[j];
            }
        }
        cout << endl;
    }
}