#include <iostream>
#include <string>

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
    int count;
    if (!(cin >> count)) return 0;

    MyLLQueue q1, q2;
    int val;

    // 플레이어 1의 카드 
    for (int i = 0; i < count; i++) {
        cin >> val;
        q1.enqueue(val);
    }

    // 플레이어 2의 카드
    for (int i = 0; i < count; i++) {
        cin >> val;
        q2.enqueue(val);
    }

    int p1_score = 0;  // P1 승점
    int p2_score = 0;   // P2 승점

    // 직전 라운드 결과 기록 (0: 시작/무승부, 1: P1승리, 2: P2승리)
    int winner = 0; 
    int p1_num = 0;
    int p2_num = 0;


    for (int round = 1; round <= count; round++) {
        int c1 = q1.getfront(); q1.dequeue();
        int c2 = q2.getfront(); q2.dequeue();

        int p1_match_num = 0;
        int p2_match_num = 0;

        if (round == 1 || winner == 0) {
            p1_match_num = c1;
            p2_match_num = c2;
        } 
        else if (winner == 1) {
            // 이전 라운드 승자가 P1일 때
            p1_match_num = c1 + (p1_num - p2_num - 1);
            p2_match_num = c2;
        } 
        else if (winner == 2) {
            // 이전 라운드 승자가 P2일 때
            p1_match_num = c1;
            p2_match_num = c2 + (p2_num - p1_num - 1);
        }

        // 이번 라운드 결과 판정 및 승점 누적
        if (p1_match_num > p2_match_num) {
            cout << "Round" << round << " - P1 win!" << endl;
            p1_score++;
            winner = 1;
        } 
        else if (p2_match_num > p1_match_num) {
            cout << "Round" << round << " - P2 win!" << endl;
            p2_score++;
            winner = 2;
        } 
        else {
            cout << "Round" << round << " - Draw!" << endl;
            winner = 0;
        }

        // 현재 대결 숫자를 다음 라운드로
        p1_num = p1_match_num;
        p2_num = p2_match_num;
    }


    if (p1_score > p2_score) {
        cout << "Final - P1 win!" << endl;
    } 
    else if (p2_score > p1_score) {
        cout << "Final - P2 win!" << endl;
    } 
    else {
        cout << "Final - Draw!" << endl;
    }

    return 0; 
}