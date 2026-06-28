#include <iostream>
#include "MyCircularQueue.h"

using namespace std; 


int MyCircularQueue::getcount() const{
    return count; 
}

void MyCircularQueue::dequeue(){
    if(isempty()) {
        cout << "=> Queue is empty !" << endl;
        return; 
    }
    front = (front + 1) % maxsize; 
    count--;
}

void MyCircularQueue::enqueue(int v){
    if(isfull()) {
        cout << "=> Queue is full !" << endl;
        return; 
    }
    rear = (rear + 1) % maxsize; 
    list[rear] = v;
    if(front == -1) front = 0;
    count++;
}

bool MyCircularQueue::isempty() const{
    return count == 0;
}

bool MyCircularQueue::isfull() const{
    return count == maxsize; 
}

int MyCircularQueue::getfront() const{
    if(isempty()) return -1;
    return list[front];
}

int MyCircularQueue::getrear() const{
    if(isempty()) return -1; 
    return list[rear];
}

void MyCircularQueue::clear(){
    front = rear = -1; 
    count = 0; 
}

void MyCircularQueue::print() const{
    cout << "Size : " << count << endl;

    cout << "Queue :";

    for(int i = 0; i < count; i++){
        int idx = (front + i) % maxsize; 
        cout << "[" << list[idx] << "]";
    }
    cout << endl;


    cout << "index :";

    for(int i = 0; i < count; i++){
        int idx = (front + i) % maxsize; 
        cout << " " << idx;
    }
    cout << endl;


    if (isempty()) {
        cout << "front : 0, rear : 0" << endl;
    } else {
        cout << "front : " << front << ", rear : " << rear << endl;
    }
}