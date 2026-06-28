#include <iostream>
#include <string>

using namespace std; 

class MyCircularQueue{
    int front; 
    int rear; 
    int maxsize; 
    int count; 
    string *list; 

    public: 
        MyCircularQueue(int size) : front(-1), rear(-1), count(0){
            if(size <= 0) size = 1; 
            list = new string[size];
            maxsize = size; 
        }
        ~MyCircularQueue(){ delete[] list; }
        void dequeue();
        void enqueue(string v);
        bool isempty() const;
        bool isfull() const;
        string getfront() const;
        string getrear() const;
        void clear();
        void print() const;
        int getcount() const; 
};