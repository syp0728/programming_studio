#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int v) : data(v), next(nullptr) {}
};


class MyLLQueue{
private:
    Node* front;
    Node* rear;
    int count; 
public:
    MyLLQueue() : count(0) {
        front = rear = nullptr; 
    }
    ~MyLLQueue(){ clear();}
    bool isempty() const{ return count == 0; }
    int getcount() const{ return count; }
    void enqueue(int v);
    void dequeue();
    void print() const;
    void clear();
    int getfront() const;
    int getrear() const;
};


void MyLLQueue::enqueue(int v){
    Node *newNode = new Node(v);

    if(isempty()){
        front = rear = newNode; 
    }else{
        rear -> next = newNode; 
        rear = newNode; 
    }

    count ++;
} 

void MyLLQueue::dequeue(){
    if(isempty())return; 
    Node* temp = front;
    front = front->next;
    delete temp;
    count--;
    if(isempty()) rear = nullptr; 
}

void MyLLQueue::print() const{
    if(isempty()){
        cout << endl;
        return;
    }

    Node* current = front;
    while(current != nullptr){
        cout << current->data;

        if(current->next != nullptr) cout << " -> ";
        current = current->next;
    }
    cout << endl;
}


void MyLLQueue::clear(){
    while(!isempty())dequeue();
}


int MyLLQueue::getfront() const{
    if(isempty()) return -1;
    return front->data;
}

int MyLLQueue::getrear() const{
    if(isempty()) return -1;
    return rear->data; 
}



int main(){
    MyLLQueue q;
    int menu;

    while(true) {
        cout << "1.enqueue 2.dequeue 3.showfront 4.showrear 5.displayQueue 6.exit > ";
        if (!(cin >> menu)) break;

        if (menu == 1) {
            int val;
            cout << "Enter a Value: ";
            cin >> val;
            q.enqueue(val);
        }
        else if (menu == 2) {
            q.dequeue();
        }
        else if (menu == 3) {
            cout << "element at front: " << q.getfront() << endl;
        }
        else if (menu == 4) {
            cout << "element at rear: " << q.getrear() << endl;
        }
        else if (menu == 5) {
            q.print();
        }
        else if (menu == 6) {
            cout << "bye!" << endl;
            break;
        }
        cout << endl; 

    return 0; 
}