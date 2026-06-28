#include <iostream>
#include "MyCircularQueue.h"

using namespace std; 


int main() {
    MyCircularQueue q(10);

    // 예시 1번
    cout << "===== Dequeue x 1 =====" << endl;
    q.dequeue(); 
    q.print();

    cout << "===== Enqueue x 7 (10 ~ 70) =====" << endl;
    for(int v = 10; v <= 70; v += 10) {
        q.enqueue(v);
    }
    q.print();

    cout << "===== Dequeue x 3 ======" << endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.print();

    // 예시 2번
    cout << "===== Enqueue x 6 (10 ~ 60) ======" << endl;
    for(int v = 10; v <= 60; v += 10) {
        q.enqueue(v); 
    }
    q.print();

    return 0;
}