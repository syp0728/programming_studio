#include <iostream>
#include <string>
#include "MyCircularQueue.h"

using namespace std; 

int main() {
    int queue_size; 
    
    if (!(cin >> queue_size)) return 0;
    
    MyCircularQueue q(queue_size);

    string cmd;
    while (cin >> cmd) {
        if (cmd == "q") {
            cout << "bye!" << endl; 
            break;
        }
        
        // enqueue ## 
        if (cmd == "en") {
            int val;
            cin >> val;
            q.enqueue(val);
        }
        // dequeue
        else if (cmd == "de") {
            q.dequeue();
        }
        // front(가장 앞에 있는 정수)
        else if (cmd == "front") {
            cout << "=> " << q.getfront() << endl;
        }
        // rear(가장 뒤에 있는 정수)
        else if (cmd == "rear") {
            cout << "=> " << q.getrear() << endl;
        }
        // size
        else if (cmd == "size") {
            cout << "=> " << q.getcount() << endl;
        }
        // empty(비어있으면 1, 아니면 0)
        else if (cmd == "empty") {
            cout << "=> " << (q.isempty() ? 1 : 0) << endl;
        }
        // print(front 값부터 rear까지의 값 출력)
        else if (cmd == "print") {
            q.print();
        }
    }

    return 0; 
}