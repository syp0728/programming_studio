#include <iostream>
#include <vector>

using namespace std; 

class MinHeap {
private:
    vector<int> heap;
    
    // 인덱스 계산을 위한 편의 함수들
    int parent(int i)     { return (i - 1) / 2; }
    int leftchild(int i)  { return 2 * i + 1; }
    int rightchild(int i) { return 2 * i + 2; }

    // 내부 정렬 규칙을 유지하기 위한 보조 함수
    void heapifyUp(int i);
    void heapifyDown(int i);

public: 
    void insert(int v);
    void removeRoot();
    int top();
    void print();
    bool empty() { return heap.empty(); }
};

// ⬆️ Heapify-Up: 새 원소가 추가되었을 때 위로 타고 올라가며 정렬
void MinHeap::heapifyUp(int i) {
    // 🔥 [변경 포인트 1] 부모 노드보다 내가 더 '작으면' 위로 swap
    while (i > 0 && heap[i] < heap[parent(i)]) {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::insert(int v) {
    heap.push_back(v);       
    heapifyUp(heap.size() - 1); 
}

// ⬇️ Heapify-Down: 루트가 삭제되었을 때 아래로 타고 내려가며 정렬
void MinHeap::heapifyDown(int i) {
    int s = heap.size();

    while (true) {
        int smallest = i; // 최솟값을 저장할 변수로 명칭 변경
        int l = leftchild(i);
        int r = rightchild(i);

        // 🔥 [변경 포인트 2] 왼쪽 자식이 존재하고, 현재 자리가 자식보다 '크면' 최솟값 인덱스 갱신
        if (l < s && heap[smallest] > heap[l])
            smallest = l;
        // 🔥 [변경 포인트 3] 오른쪽 자식이 존재하고, 현재 자리가 자식보다 '크면' 최솟값 인덱스 갱신
        if (r < s && heap[smallest] > heap[r])
            smallest = r;

        // 자식들이 나보다 다 커서 교환이 필요 없으면 탈출
        if (smallest == i) break;

        swap(heap[i], heap[smallest]);
        i = smallest; 
    }
}

void MinHeap::removeRoot() {
    if (heap.empty()) return;

    // 맨 뒤의 원소를 루트 자리로 끌어올린 후 마지막 원소 제거
    heap[0] = heap.back();
    heap.pop_back();
    
    // 루트 자리(0번 인덱스)부터 아래로 정렬 시작
    if (!heap.empty()) {
        heapifyDown(0);
    }
}

// 🔝 최솟값(루트 노드) 확인
int MinHeap::top() {
    if (heap.empty()) return -1; 
    return heap[0];
}

// 🖨️ 힙 내부 상태 출력
void MinHeap::print() {
    cout << "==> Min Heap : ";
    for (int v : heap) cout << v << " ";
    cout << endl;
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    MinHeap h;
    int menu;
    
    while (true) {
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
            if(h.empty()) {
                cout << "=> Heap is Empty!\n";
            } else {
                cout << "=> Delete (Min): " << h.top() << "\n"; 
                h.removeRoot();
                h.print();
            }
        }
        else if (menu == 3) {
            h.print();
        }
        else break;
    }

    cout << "Bye!" << endl;
    return 0;
}