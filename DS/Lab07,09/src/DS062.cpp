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

    count++;
}

void MyLLQueue::dequeue(){
    if(isempty()) return; 

    Node* temp = front; 
    front = front -> next; 

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
        cout << current -> data; 

        if(current -> next != nullptr) cout << " -> ";
        current = current -> next; 
    }
    cout << endl; 

}

void MyLLQueue::clear(){
    while(!isempty()) dequeue();
}

int MyLLQueue::getfront() const{
    if(isempty()) return -1; 
    return front -> data; 

}

int MyLLQueue::getrear() const{
    if(isempty()) return -1; 
    return rear -> data; 
}


int main(){
    int n;
    if (!(cin >> n)) return 0;

    // 1부터 20까지의 정수
    if (n < 1 || n > 20) return 0;

    MyLLQueue q;
    int result = 0;

    for (int i = 1; i <= n; i++) {
        // 접미사
        string suffix = "th";
        if (i == 1) suffix = "st";
        else if (i == 2) suffix = "nd";
        else if (i == 3) suffix = "rd";

        int current= 0;

        if (i == 1 || i == 2) {
            current = 1;
            q.enqueue(current);
        } else {
            int fib_minus_2 = q.getfront();
            q.dequeue();
            
            int fib_minus_1 = q.getfront(); 
            
            current = fib_minus_2 + fib_minus_1;
            q.enqueue(current);
        }

        cout << i << suffix << " : " << current << endl;
        
        if (i == n) {
            result = current;
        }
    }

    cout << "=> fibonacci(" << n << ") : " << result << endl;

    return 0; 
}