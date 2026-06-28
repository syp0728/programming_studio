#include <iostream>

using namespace std; 

class MyStack{
        string *list = nullptr; 
        int top; 
        int size; 
    public: 
        MyStack(int size){
            this->size = size;
            list = new string[size];
            top = -1;
        }
        ~MyStack(){
            delete[] list; 
        }

        void push(string &v);
        string pop();
        bool is_empty() const;
        bool is_full() const;
        void clear();
        void print();
};
