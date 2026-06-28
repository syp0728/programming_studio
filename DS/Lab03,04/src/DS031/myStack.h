#include <iostream>

using namespace std; 

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