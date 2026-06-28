#include <iostream>
#include <string>

using namespace std; 

class Node {
    public: 
        char data; // int -> char로 변경
        Node* next; 
        Node(char v) : data(v), next(nullptr) {
        }
};


class MyLinkedListStack {
    private: 
        Node* top;
    public: 
        MyLinkedListStack() : top(nullptr) {};
        ~MyLinkedListStack() { clear(); }
        void push(const char& v); // int -> char로 변경
        void pop();
        char peek() const;        // int -> char로 변경
        bool isempty() const;
        void clear();
        void printall() const;
        int getcnt() const;
};

void MyLinkedListStack::push(const char& v) {
    Node *newnode = new Node(v);
    newnode->next = top; 
    top = newnode; 
}

void MyLinkedListStack::pop() {
    if (isempty()) return; 
    Node *tempnode = top; 
    top = tempnode->next; 
    delete tempnode; 
}

char MyLinkedListStack::peek() const {
    if (isempty()) return '\0'; // char로 변경
    return top->data;
}

bool MyLinkedListStack::isempty() const {
    return top == nullptr;
}

void MyLinkedListStack::clear() {
    while (top != nullptr) pop();
}

void MyLinkedListStack::printall() const {
    if (isempty()) {
        cout << "Stack is empty" << endl;
        return;
    }
    Node *tempnode = top;
    int count = getcnt(); 
    int current = 0;
    while (tempnode != nullptr) {
        cout << tempnode->data;
        current++;
        if (current < count) cout << " -> "; 
        tempnode = tempnode->next; 
    }
    cout << " (" << count << " nodes)" << endl;
}

int MyLinkedListStack::getcnt() const {
    Node *tempnode = top;
    int count = 0; 
    while (true) {
        if (tempnode == nullptr) break;
        count++; 
        tempnode = tempnode->next; 
    }
    return count; 
}

int main() {
    string input_line;

    while (getline(cin, input_line)) {
        if (input_line.empty()) continue;
        
        if (input_line == "q") {
            break;
        }

        // 커서 기준 left 스택, right 스택 생성
        MyLinkedListStack left_stack;
        MyLinkedListStack right_stack;

        // 문자열을 하나씩 분석
        for (int i = 0; i < input_line.length(); i++) {
            char ch = input_line[i];

            if (ch == '<') {
                // 커서를 왼쪽으로 이동 -> left에서 하나 꺼내 right로 이동
                if (!left_stack.isempty()) {
                    right_stack.push(left_stack.peek());
                    left_stack.pop();
                }
            } 
            else if (ch == '>') {
                // 커서를 오른쪽으로 이동 -> right에서 하나 꺼내 left로 이동
                if (!right_stack.isempty()) {
                    left_stack.push(right_stack.peek());
                    right_stack.pop();
                }
            } 
            else {
                // 일반 문자 입력 -> left 스택에 삽입
                left_stack.push(ch);
            }
        }

        // 출력 데이터 조립
        // left_stack에 있는 데이터를 모두 right_stack으로 옮겨서 정방향 순서로
        while (!left_stack.isempty()) {
            right_stack.push(left_stack.peek());
            left_stack.pop();
        }

        cout << "=> ";
        while (!right_stack.isempty()) {
            cout << right_stack.peek();
            right_stack.pop();
        }
        cout << endl;
    }

    return 0;
}