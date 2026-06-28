#include "myStack.h"
#include <iostream>
#include <fstream>

using namespace std;


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