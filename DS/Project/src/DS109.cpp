#include <iostream>

using namespace std;
class MyStack {
private:
    char arr[100]; 
    int topIndex;     

public:
    MyStack();
    ~MyStack() {}

    void push(char c);
    void pop();
    char top();
    int size();
    bool isEmpty();
    char get(int index);
};

MyStack::MyStack() {
    topIndex = -1; 
}

void MyStack::push(char c) {
    topIndex++;
    arr[topIndex] = c;
}

void MyStack::pop() {
    if (!isEmpty()) {
        topIndex--;
    }
}

char MyStack::top() {
    if (!isEmpty()) {
        return arr[topIndex];
    }
    return '\0';
}

int MyStack::size() {
    return topIndex + 1;
}

bool MyStack::isEmpty() {
    return topIndex == -1;
}

char MyStack::get(int index) {
    return arr[index];
}

char inputStr[100];

int main() {
    while (cin >> inputStr) {
        MyStack st; 

        for (int i = 0; inputStr[i] != '\0'; i++) {
            char current_char = inputStr[i];

            if (!st.isEmpty() && st.top() == current_char) {
                st.pop();
            } 
            else {
                st.push(current_char);
            }
        }

        int finalSize = st.size();
        for (int i = 0; i < finalSize; i++) {
            cout << st.get(i);
        }
        cout << "\n";
        break; 

    }

    return 0;
}