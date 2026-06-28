#include <iostream>

using namespace std;

class MyQueue {
private:
    int arr[100]; 
    int frontIndex;   
    int rearIndex;   
    int max;     

public:
    MyQueue();
    ~MyQueue() {}

    void push(int value);
    void pop();
    int front();
    int size();
    bool isEmpty();
};

MyQueue::MyQueue() {
    frontIndex = 0;
    rearIndex = 0;
    max = 100;
}

void MyQueue::push(int value) {
    arr[rearIndex] = value;
    rearIndex = (rearIndex + 1) % max; // 원형 큐
}

void MyQueue::pop() {
    if (!isEmpty()) {
        frontIndex = (frontIndex + 1) % max;
    }
}

int MyQueue::front() {
    if (!isEmpty()) {
        return arr[frontIndex];
    }
    return -1;
}

int MyQueue::size() {
    return (rearIndex - frontIndex + max) % max;
}

bool MyQueue::isEmpty() {
    return frontIndex == rearIndex;
}

int main() {
    int n;
    if (cin >> n) {
        MyQueue q;

        // 1부터 N까지의 카드를 순서대로 큐에 삽입
        for (int i = 1; i <= n; i++) {
            q.push(i);
        }

        // 카드가 1장 남을 때까지 규칙 반복
        while (q.size() > 1) {
            q.pop(); // 맨 위의 카드는 버림
        
            int topCard = q.front();
            q.pop();
            q.push(topCard); // 맨 위의 카드를 가장 아래 쪽으로 넣는다
        }

        // 마지막으로 남은 한 장의 카드 번호 출력
        cout << q.front() << "\n";
    }

    return 0;
}