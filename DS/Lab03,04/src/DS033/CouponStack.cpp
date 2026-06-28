#include "CouponStack.h"
#include <iostream>

using namespace std; 

void CouponStack::initialize(){
    top = -1; 
}

bool CouponStack::is_empty() const{
    return top == -1; 
}
bool CouponStack::is_full() const{
    return top == maxsize - 1; 
}

void CouponStack::push(const coupon &c){
    if(is_full()){
        cout << "CouponStack is full" << endl; 
        return; 
    }
    list[++top] = c; 
}

coupon* CouponStack::pop(){
    if(is_empty()){
        cout << "CouponStack is empty" << endl; 
        return nullptr; 
    }
    return &list[top--]; 
}


void CouponStack::print(){
    for(int i = top; i >= 0; i--){
        cout << list[i].rank << "등 - " << list[i].name << endl; 
    }
}

void CouponStack::rprint(){
    while(!is_empty()){
        coupon* c = pop(); 
        if(c != nullptr){
            cout << c->rank << "등 - " << c->name << endl; 
        }
    }
}