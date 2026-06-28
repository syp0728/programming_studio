#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> data;

    void heapifyUp(int idx) {
        while (idx > 0 && data[idx] > data[(idx - 1) / 2]) {
            swap(data[idx], data[(idx - 1) / 2]);
            idx = (idx - 1) / 2;
        }
    }

    void heapifyDown(int idx) {
        int size = data.size();
        while (2 * idx + 1 < size) {
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;
            int largest = idx;

            if (left < size && data[left] > data[largest]) largest = left;
            if (right < size && data[right] > data[largest]) largest = right;

            if (largest != idx) {
                swap(data[idx], data[largest]);
                idx = largest;
            } else break;
        }
    }

public:
    void insert(int val) {
        data.push_back(val);
        heapifyUp(data.size() - 1);
    }

    int extract() {
        if (data.empty()) return -1;
        int top = data[0];
        data[0] = data.back();
        data.pop_back();
        heapifyDown(0);
        return top;
    }

    int size() const {
        return data.size();
    }

    bool empty() const {
        return data.empty();
    }

    vector<int> getData() const {
        return data;
    }

    // k번째로 큰 값을 반환
    int extractKth(int k){

        
// d
        return -1;
    }
};

int main() {
    MaxHeap h;
    h.insert(90);
    h.insert(80);
    h.insert(70);
    h.insert(60);
    h.insert(50);

    cout << "Original heap : ";
    for (int x : h.getData()) cout << x << " " ;
    cout << endl<< endl;

    cout << "3rd largest: " << h.extractKth(3) << endl<< endl; // 70

    cout << "Original heap : ";
    for (int x : h.getData()) cout << x << " ";
    cout << endl;

    return 0;
}