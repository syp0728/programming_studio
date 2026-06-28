#include "myStack.h"
#include <iostream>

using namespace std;


bool MyStack::is_empty() const{
    return top == -1; 
}
bool MyStack::is_full() const{
    return top == maxsize; 
}

void MyStack::push(int &v){
    if(is_full()){
        cout << "MyStack is full" << endl; 
        return; 
    }
    list[++top] = v; 

}

int MyStack::pop(){
    if(is_empty()){
        cout << "MyStack is empty" << endl; 
        return 0; 
    }
    return list[top--]; 
}

void MyStack::print(){
    for(int i = top; i >= 0; i--){
        cout << list[i] << endl; 
    }
}

