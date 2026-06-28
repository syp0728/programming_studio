#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& list) {
    int s = list.size();
    for (int i = 0; i < s - 1; i++) {
        int key = list[i + 1];
        int j = i;

        while (j >= 0 && list[j] > key) {
            list[j + 1] = list[j];
            j--;
        }
        list[j + 1] = key;
    }
}

int main() {
    int n;
    if (!(cin >> n)) return 0; 

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i]; 
    }

    insertionSort(nums);
    
    cout << nums[n / 2] << "\n";

    return 0;
}