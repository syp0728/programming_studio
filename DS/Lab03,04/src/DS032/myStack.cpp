#include "myStack.h"
#include <iostream>

using namespace std; 

bool MyStack::is_empty() const{
    return top == -1; 
}
bool MyStack::is_full() const{
    return top == size - 1; 
}

void MyStack::push(string &v){
    if(is_full()){
        cout << "MyStack is full" << endl; 
        return; 
    }
    list[++top] = v; 

}

string MyStack::pop(){
    if(is_empty()){
        cout << "MyStack is empty" << endl; 
        return ""; 
    }
    return list[top--]; 
}

void MyStack::clear(){
    top = -1; 
}

void MyStack::print(){
    for(int i = top; i >= 0; i--){
        cout << list[i] << endl; 
    }
}
