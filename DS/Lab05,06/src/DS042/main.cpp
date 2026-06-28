#include <iostream>
#include <string>
#include <fstream> 

using namespace std; 

class Node {
public: 
    int data; 
    Node* next; 
    Node(int v) : data(v), next(nullptr) {}
};

class MyLinkedListStack {
private: 
    Node* top;
public: 
    MyLinkedListStack() : top(nullptr) {};
    ~MyLinkedListStack() { clear(); }
    void push(const int& v);
    void pop();
    int peek() const; 
    bool isempty() const;
    void clear();
    void printall() const;
    int getcnt() const;
};

void MyLinkedListStack::push(const int& v) {
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

int MyLinkedListStack::peek() const {
    if (isempty()) return -1; 
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
    MyLinkedListStack mystack;
    ifstream inFile("input.txt"); 

    if (!inFile.is_open()) {
        cout << "Error: input.txt" << endl;
        return 1;
    }

    string line;

    while (getline(inFile, line)) {
        if (line.empty()) continue;

        cout << line << endl;

        bool is_error = false;
        string error_msg = "";
        mystack.clear(); // 스택 비우기

        size_t start = 0;
        size_t end = 0;

        while (start < line.length()) {
            // 공백 건너뛰기
            while (start < line.length() && line[start] == ' ') {
                start++;
            }
            if (start >= line.length()) break; // 줄 끝에 도달하면 반복문 탈출

            // 공백 전까지의 토큰 범위 찾기
            end = start;
            while (end < line.length() && line[end] != ' ') {
                end++;
            }

            // 토큰 하나 추출
            string token = line.substr(start, end - start);
            start = end; // 다음 루프를 위해 인덱스 이동

            if (token[0] == '#') {
                if (token.length() == 1) { 
                    is_error = true;
                    error_msg = "Expression error !!!";
                    break;
                }
                int num = stoi(token.substr(1)); 
                mystack.push(num);
            }

            else if (token == "+" || token == "-" || token == "*" || token == "/") {
                if (mystack.getcnt() < 2) { 
                    is_error = true;
                    error_msg = "Expression error !!!";
                    break;
                }

                int op2 = mystack.peek(); mystack.pop(); 
                int op1 = mystack.peek(); mystack.pop(); 
                int res = 0;

                if (token == "+") res = op1 + op2;
                else if (token == "-") res = op1 - op2;
                else if (token == "*") res = op1 * op2;
                else if (token == "/") {
                    if (op2 == 0) { 
                        is_error = true;
                        error_msg = "Division by 0";
                        break;
                    }
                    res = op1 / op2;
                }
                mystack.push(res);
            }

            else if (token == "=") {
                break;
            }

            else {
                is_error = true;
                error_msg = "Expression error !!!";
                break;
            }
        }

        // 출력
        if (!is_error) {
            if (mystack.isempty()) {
                cout << "=> Expression error !!!" << endl;
            } 
            else if (mystack.getcnt() > 1) { 
                cout << "=> Too many operands !!!" << endl;
            } 
            else { 
                cout << mystack.peek() << endl;
            }
        } 
        else { 
            cout << "=> " << error_msg << endl;
        }
    }

    inFile.close(); 
    return 0;
}