#include <iostream>
#include <string>

using namespace std; 

class MyCircularQueue{
    int front; 
    int rear; 
    int maxsize; 
    int count; 
    int *list; 

    public: 
        MyCircularQueue(int size) : front(-1), rear(-1), count(0){
            if(size <= 0) size = 1; 
            list = new int[size];
            maxsize = size; 
        }
        ~MyCircularQueue(){ delete[] list; }
        void dequeue();
        void enqueue(int v);
        bool isempty() const;
        bool isfull() const;
        int getfront() const;
        int getrear() const;
        void clear();
        void print() const;
        int getcount() const; 
};