#include <iostream>

using namespace std;

// Node 구조 (기존과 동일)
class Node {
public:
    int data;
    Node* next;
    Node(int v) : data(v), next(nullptr) {}
};

// MyLLPriorityQueue 클래스 (함수 통합 버전)
class MyLLPriorityQueue {
private:
    Node* front;
    Node* rear;
    int count;

public:
    MyLLPriorityQueue() : front(nullptr), rear(nullptr), count(0) {}
    
    ~MyLLPriorityQueue() { 
        clear(); 
    }

    bool isempty() const { return count == 0; }
    int getcount() const { return count; }

    // 1. 우선순위에 맞게 정렬하여 삽입 (Enqueue)
    // 여기서는 값이 클수록 우선순위가 높은 Max-Priority Queue로 구현했습니다.
    void enqueue(int v) {
        Node* newNode = new Node(v);

        // 큐가 비어있거나, 새 데이터가 현재 가장 큰 값(front보다 큼)인 경우 맨 앞에 삽입
        if (isempty() || v > front->data) {
            newNode->next = front;
            front = newNode;
            if (rear == nullptr) rear = newNode; // 첫 노드일 때 rear 설정
        } 
        else {
            // 새 데이터가 들어갈 올바른 위치 탐색 (자기보다 작은 값 직전까지 이동)
            Node* current = front;
            while (current->next != nullptr && current->next->data >= v) {
                current = current->next;
            }

            // 노드 연결 변경
            newNode->next = current->next;
            current->next = newNode;

            // 만약 맨 뒤에 삽입되었다면 rear 갱신
            if (newNode->next == nullptr) {
                rear = newNode;
            }
        }

        count++;
    }

    // 2. 가장 우선순위가 높은 데이터 제거 (Dequeue) - 항상 front에서 제거되므로 기존과 동일
    void dequeue() {
        if (isempty()) return;
        
        Node* temp = front;
        front = front->next;
        delete temp;
        count--;

        if (isempty()) rear = nullptr;
    }

    // 3. 전체 큐 출력
    void print() const {
        if (isempty()) {
            cout << "(Empty Queue)" << endl;
            return;
        }

        Node* current = front;
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) cout << " -> ";
            current = current->next;
        }
        cout << endl;
    }

    // 4. 전체 초기화
    void clear() {
        while (!isempty()) {
            dequeue();
        }
    }

    // 최고 우선순위 값 확인 (가장 큰 값)
    int getfront() const {
        if (isempty()) return -1;
        return front->data;
    }

    // 최저 우선순위 값 확인 (가장 작은 값)
    int getrear() const {
        if (isempty()) return -1;
        return rear->data;
    }
};

int main() {
    MyLLPriorityQueue pq;
    int menu;

    // 원본 코드의 메인 루프 내부 중괄호 짝 오류를 수정했습니다.
    while (true) {
        cout << "1.enqueue 2.dequeue 3.showfront(Max) 4.showrear(Min) 5.displayQueue 6.exit > ";
        if (!(cin >> menu)) break;

        if (menu == 1) {
            int val;
            cout << "Enter a Value: ";
            cin >> val;
            pq.enqueue(val);
        }
        else if (menu == 2) {
            pq.dequeue();
            cout << "Dequeued highest priority element." << endl;
        }
        else if (menu == 3) {
            cout << "Highest priority element: " << pq.getfront() << endl;
        }
        else if (menu == 4) {
            cout << "Lowest priority element: " << pq.getrear() << endl;
        }
        else if (menu == 5) {
            pq.print();
        }
        else if (menu == 6) {
            cout << "bye!" << endl;
            break;
        }
        cout << endl;
    }

    return 0;
}