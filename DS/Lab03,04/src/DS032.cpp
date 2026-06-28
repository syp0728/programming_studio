#include <iostream>
#include <fstream>
using namespace std; 

/**
 * 
 * list / size / top
 * push / pop / infull / isempty
 * print
 * 
 */

class MyStack{
        string *list = nullptr; 
        int top; 
        int size; 
    public: 
        MyStack(int size){
            this->size = size;
            list = new string[size];
            top = -1;
        }
        ~MyStack(){
            delete[] list; 
        }

        void push(string &v);
        string pop();
        bool is_empty() const;
        bool is_full() const;
        void clear();
        void print();
};

bool MyStack::is_empty() const{
    return top == -1; 
}
bool MyStack::is_full() const{
    return top == size - 1; 
}

void MyStack::push(string &v){
    if(is_full()){
        cout << "MyStack is full" << endl; 
        return; 
    }
    list[++top] = v; 

}

string MyStack::pop(){
    if(is_empty()){
        cout << "MyStack is empty" << endl; 
        return ""; 
    }
    return list[top--]; 
}

void MyStack::clear(){
    top = -1; 
}

void MyStack::print(){
    for(int i = top; i >= 0; i--){
        cout << list[i] << endl; 
    }
}


int main() {

    string filename = "GPA2.txt";
    ifstream fin(filename);

    if(!fin.is_open()) {
        cout << "Can't open file: " << filename << endl;
        return 1; 
    }

    MyStack mystack(100);

    double max_gpa = -1.0; 
    double gpa; 
    string name; 

    while(fin >> gpa >> name) {
        if(gpa > max_gpa) {
            max_gpa = gpa; 
            mystack.clear();
            mystack.push(name); 
        }else if(gpa == max_gpa) {
            mystack.push(name);
        }
    }

    fin.close();

    cout << "Top GPA: " << max_gpa << endl; 
    mystack.print();

    return 0; 
}