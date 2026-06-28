#include "myStack.h"
#include <iostream>

using namespace std;


int main() {
    int size; 
    cin >> size; 

    MyStack mystack(size);
    while(true){
        string cmd; 
        cin >> cmd; 

        if(cmd == "quit") break; 
        if(cmd == "push"){
            int value; 
            cin >> value; 
            mystack.push (value);
        }
        else if(cmd == "pop"){
            mystack.pop();
        }
        else if(cmd == "print"){
            mystack.print();
        }
    }

    cout << "Bye!" << endl;
    return 0; 
}