#include <iostream>
using namespace std; 

/**
 * 
 * list / size / top
 * push / pop / infull / isempty
 * print
 * 
 */

class MyStack{
        int *list = nullptr; 
        int top; 
        int size; 
        int maxsize; 
    public: 
        MyStack(int size){
            this->size = size;
            this->maxsize = size;
            list = new int[size];
            top = -1;
        }
        ~MyStack(){
            delete[] list; 
        }

        void push(int &v);
        int pop();
        bool is_empty() const;
        bool is_full() const;
        void print();
};

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