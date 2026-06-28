#include <iostream>

using namespace std; 

class MinHeap {
private: 
    int arr[30];
    int length; 

    int parent(int i) { return (i - 1) / 2; }
    int leftchild(int i) { return 2 * i + 1; }
    int rightchild(int i) { return 2 * i + 2; }

public: 
    MinHeap() {
        length = 0; 
    }
    ~MinHeap() {} 
    
    void insertKey(int value); 
    int deleteKey(); 
    int peek(); 
    int size();
    bool isEmpty(); 
    void minHeapifyUp(int index);
    void minHeapifyDown(int root = 0);
    void printHeap(); 
    void clear();
};

void MinHeap::insertKey(int value){
    if (length >= 30) return;
    arr[length] = value;
    length++;
    minHeapifyUp(length - 1);
}

int MinHeap::deleteKey(){
    if (isEmpty()) return -1;
        
    int rootValue = arr[0];
    arr[0] = arr[length - 1];
    length--;
    
    if (!isEmpty()) {
        minHeapifyDown(0);
    }
    return rootValue;
}

int MinHeap::peek(){
    if (isEmpty()) return -1;
    return arr[0];
}

int MinHeap::size(){
    return length; 
}

bool MinHeap::isEmpty(){
    return length == 0; 
}

void MinHeap::minHeapifyUp(int index){
    while (index > 0 && arr[index] < arr[parent(index)]) {
        swap(arr[index], arr[parent(index)]);
        index = parent(index);
    }
}

void MinHeap::minHeapifyDown(int root){
    while (true) {
        int smallest = root;
        int l = leftchild(root);
        int r = rightchild(root);

        if (l < length && arr[smallest] > arr[l])
            smallest = l;
        if (r < length && arr[smallest] > arr[r])
            smallest = r;

        if (smallest == root) break;

        swap(arr[root], arr[smallest]);
        root = smallest;
    }
}

void MinHeap::printHeap(){
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void MinHeap::clear(){
    length = 0; 
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    MinHeap mh;
    int menu;

    while (true) {
        cout << "1. Array to minHeap 2.insert 3.delete 4.print 0.quit > ";
        if (!(cin >> menu)) break;

        if (menu == 1) {
            int n, val;
            cin >> n;
            mh.clear(); 
            for (int i = 0; i < n; i++) {
                cin >> val;
                mh.insertKey(val); 
            }
            cout << "minHeap => ";
            mh.printHeap();
        }
        else if (menu == 2) {
            int val;
            cin >> val;
            mh.insertKey(val); 
            cout << "minHeap => ";
            mh.printHeap();
        }
        else if (menu == 3) {
            int deleted = mh.deleteKey(); 
            if (deleted != -1) {
                cout << "min value : " << deleted << "\n";
                cout << "minHeap => ";
                mh.printHeap();
            }
        }
        else if (menu == 4) {
            mh.printHeap();
        }
        else if (menu == 0) {
            cout << "bye!\n";
            break;
        }
    }

    return 0;
}