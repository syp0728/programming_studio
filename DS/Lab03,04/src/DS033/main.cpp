#include "CouponStack.h"
#include <iostream>

using namespace std; 

int main() {
    int size; 
    cin >> size; 

    CouponStack stack(size);
    char cmd; 

    while(cin >> cmd){
        if(cmd == 'q') break;
        else if(cmd == '+') {
            coupon c;
            cin >> c.rank;
            cin.ignore(); 
            getline(cin, c.name);
            stack.push(c);
        }else if(cmd == '-') {
            coupon* c = stack.pop();
            if(c != nullptr){
                cout << c->rank << "등 - " << c->name << endl; 
            }else{
                cout << "Stack is empty" << endl;
            }
        }
    }

    return 0;
}

