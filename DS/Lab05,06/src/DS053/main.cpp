#include <iostream>
#include <fstream>
#include <string>
#include "MyCircularQueue.h"

using namespace std;

int main() {
    string filename = "data.txt"; 
    ifstream fin(filename);

    if(!fin.is_open()) {
        cout << "Can't open file: " << filename << endl;
        return 1; 
    }

    MyCircularQueue q(100);

    double max_gpa = -1.0; 
    double gpa; 
    string name; 

    while(fin >> gpa >> name) {
        if(gpa > max_gpa) {
            max_gpa = gpa; 
            q.clear();         // 더 높은 평점이 나오면 기존 저장 명단 리셋
            q.enqueue(name);   
        } 
        else if(gpa == max_gpa) {
            q.enqueue(name);   // 동점자일 경우 큐 뒤쪽에 추가
        }
    }
    fin.close();

    cout << "Highest GPA = " << max_gpa << endl; 
    
    while(!q.isempty()) {
        cout << q.getfront() << " " << max_gpa << endl;
        q.dequeue();
    }

    return 0; 
}