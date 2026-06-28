#include <iostream>
#include <fstream>
using namespace std;

class CQueue {    
    int front, rear;
    int maxsize;
    string *list;
public:
    CQueue(int size) : front(0), rear(0){
        maxsize = size;
        maxsize ++;
        list = new string[maxsize];        
    }
    ~CQueue(){  delete[] list;}
    void enqueue(string val){
        if(isFull()) return ;
        list[rear] = val;
        rear = (rear + 1) % maxsize; 
    }
    string dequeue(){
        if(isEmpty()) return nullptr;
        string val = list[front];
        front = (front+1) % maxsize;
        return val;
    }
    bool isFull(){
        return (rear+1)%maxsize == front;
    }
    bool isEmpty(){
        return front == rear;
    }

    void clear(){
        front = rear = 0;
    }

    string frontItem(){
        if(isEmpty()) return nullptr;
        return list[front];
    }
    string rearItem(){
        if(isEmpty()) return nullptr;
        int idx = (rear-1+maxsize) % maxsize;
        return list[idx];
    }

    void display(){
        if(isEmpty()) return ;
        int i  = front;
        while( i!= rear){
            cout << list[i] << " -> ";
            i = (i+ 1) %maxsize;
        }
        cout << endl;
    }
};


void saveToFile(){
    ofstream of("aitools.txt");
    of << "Hello"; 
    of.close();
}

int main(){    
    int size; 
    cin >> size; 
    CQueue queue(size);

    for(int i=0; i<size; i++){
        string val; 
        cin >> val; 
        queue.enqueue(val);
        // saveToFile(val); 
    }

    cout << "==========" << endl; 
    queue.display();   
    cout << endl; 
    return 0;
}
