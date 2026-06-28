#include <iostream>
#include <vector> // push_back(), pop_back(), empty(), size(), front(), back() .......

using namespace std; 

class Makeheap{
    vector<int> heap;
    int parent(int i){ return (i-1)/2; }
    int leftchild(int i){ return 2*i + 1; }
    int rightchild(int i){ return 2*i + 2; }

public: 
    void insert(int v);
    void removeRoot();
    int top();
    void print();
};

void Makeheap::insert(int v){   // heapfiy-up
    heap.push_back(v);
    int i = heap.size() - 1;

    while(i > 0 && heap[i] > heap[parent(i)]){
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}


void Makeheap::removeRoot(){    // heapfiy-down
    if(heap.empty()) return;

    heap[0] = heap.back();
    heap.pop_back();
    
    int i = 0;
    int s = heap.size();

    while(true){
        int largest = i;
        int l = leftchild(i);
        int r = rightchild(i);

        if(l < s && heap[largest] < heap[l])
            largest = l;
        if(r < s && heap[largest] < heap[r])
            largest = r;

        if(largest == i) break;

        swap(heap[i], heap[largest]);
        i = largest; 
    }
}

int Makeheap::top(){
    if(heap.empty()) return -1;
    return heap[0];
}

void Makeheap::print(){
    cout << "==> Heap : ";
    for(int v : heap) cout << v << " ";
    cout << endl;
}

int main(){
    Makeheap h;
    int menu;
    while (1) {
        cout << "1. insert 2. delete 3. print 4. quit > ";
        cin >> menu;

        if (menu == 1) {
            int value;
            cout << "new value? ";
            cin >> value;
            h.insert(value);
            h.print();
        }
        else if (menu == 2) {
            cout << "=> Delete " << h.top() << endl; 
            h.removeRoot();
            h.print();
        }
        else if (menu == 3) {
            h.print();
        }
        else break;
    }

    cout << "Bye!" << endl;
    return 0;
}