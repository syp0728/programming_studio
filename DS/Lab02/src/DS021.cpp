#include <iostream>

using namespace std; 

class Student {
    private: 
        double getAvg() const;          // const = 멤버 변수의 값을 변경하지 않는다. 
    public: 
        string name; 
        string sid; 
        int *score; 
        void print() const {
            cout << "[" << sid << "] " << name << endl;  
            printf("The Average score is %.1f\n", getAvg());
        }
};

double Student::getAvg() const {
    int n = 3, sum = 0; 

    for(int i=0; i<n; i++) 
        sum += score[i];
    
    return (double)sum / n;
}

int main() {
    int n = 3;
    Student s1; 
    s1.score = new int[n];  // 생성자

    cin >> s1.sid; 
    for(int i=0; i<n; i++) 
        cin >> s1.score[i];
    cin.ignore();               // 입력버퍼를 비워주는 함수
    getline(cin, s1.name);

    s1.print();

    delete[] s1.score;      // 소멸자
    return 0; 
}