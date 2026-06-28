#include <iostream>
#include <string>
#include "MyCircularQueue.h"

using namespace std; 

int MyCircularQueue::getcount() const{
    return count; 
}

void MyCircularQueue::dequeue(){
    if(isempty()) {
        return; 
    }
    front = (front + 1) % maxsize; 
    count--;
}

void MyCircularQueue::enqueue(int v){
    if(isfull()) {
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
    if (isempty()) {
        return;
    }

    for(int i = 0; i < count; i++){
        int idx = (front + i) % maxsize; 
        cout << list[idx];
        if (i < count - 1) {
            cout << " => ";
        }
    }
    cout << endl;
}