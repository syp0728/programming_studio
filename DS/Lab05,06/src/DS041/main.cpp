#include <iostream>

using namespace std; 


// Node - 값1 (int), 포인터1
class Node {
    public: 
        int data; 
        Node* next; 
        Node(int v) : data(v), next(nullptr){
        }

};

// MyLinkedListStack
class MyLinkedListStack {
    private: 
        Node* top;
    public: 
        MyLinkedListStack() : top(nullptr) {};
        ~MyLinkedListStack() {clear();}
        void push(const int& v);
        void pop();
        int peek() const; 
        bool isempty() const;
        void clear();
        void printall() const;
        int getcnt() const;

};

void MyLinkedListStack::push(const int& v){
    // 노드를 만든다. 
    // 노드의 결과 next에 top을 연결한다. 
    // top을 새 노드에 연결한다. 
    Node *newnode = new Node(v);
    newnode->next = top; 
    top = newnode; 

}

void MyLinkedListStack::pop(){
    Node *tempnode = top; 
    top = tempnode->next; 
    delete tempnode; 
    
}

int MyLinkedListStack::peek() const{
    if(isempty()) return -1; 
    return top->data;
}

bool MyLinkedListStack::isempty() const{
    return top == nullptr;
}

void MyLinkedListStack::clear(){
    while(top != nullptr) pop();
    // while(isempty()) pop();
}

void MyLinkedListStack::printall() const{
    if (isempty()) {
        cout << "Stack is empty" << endl;
        return;
    }

    Node *tempnode = top;
    int count = getcnt(); 
    int current = 0;

    while(tempnode != nullptr){
        cout << tempnode->data;
        current++;
        
        if (current < count) cout << " -> "; 
        
        tempnode = tempnode->next; 
    }
    cout << " (" << count << " nodes)" << endl;
}

int MyLinkedListStack:: getcnt() const{
    Node *tempnode = top;
    int count = 0; 
    while(true){
        if(tempnode == nullptr) break;
        count++; 
        tempnode = tempnode->next; 
    }
    return count; 
}


int main() {
    MyLinkedListStack mystack;

    string outputs[100];
    int out_count = 0;

    while(true){
        string cmd; 
        cin >> cmd; 

        if(cmd == "q"){
            break; 
        }
        if(cmd == "push"){
            int value; 
            cin >> value; 
            mystack.push(value);
        }
        else if(cmd == "pop"){
            mystack.pop();
        }
        else if(cmd == "print"){
            if (mystack.isempty()) {
                outputs[out_count++] = "Stack is empty\n";
            } 
            else {
                string temp_str = "";
                int count = mystack.getcnt();
                
                int* temp_arr = new int[count];
                for(int i = 0; i < count; i++) {
                    temp_arr[i] = mystack.peek();
                    mystack.pop();
                }
                
                for(int i = count - 1; i >= 0; i--) {
                    mystack.push(temp_arr[i]); 
                }
                
                for(int i = 0; i < count; i++) {
                    temp_str += to_string(temp_arr[i]);
                    if (i < count - 1) temp_str += " -> ";
                }
                temp_str += " (" + to_string(count) + " nodes)\n";
                
                outputs[out_count++] = temp_str;
                delete[] temp_arr; 
            }
        }
        else if(cmd == "clear"){
            mystack.clear();
        }
        else if(cmd == "peek"){
            if (mystack.peek() != -1) {
                outputs[out_count++] = to_string(mystack.peek()) + "\n";
            }
        }
    }

    for(int i = 0; i < out_count; i++) {
        cout << outputs[i];
    }

    cout << "Bye!" << endl;
    return 0;
}