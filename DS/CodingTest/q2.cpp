#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;             

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;                  
        }
    }

    swap(arr[i], arr[high]);
    return i;         
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high); 
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void printArrayDesc(int arr[], int n) {
    for (int i = n; i > 0; i--)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    // int data[] = {10, 7, 8, 9, 1, 5};
    // int n = sizeof(data) / sizeof(data[0]);
    int n;
    cin >> n; 

    int *data = new int[n];

    for(int i=0; i<n; i++) {
        cin >> data[i];
    }

    string method; 
    cin >> method; 

    quickSort(data, 0, n - 1);

    if(method == "asc"){
        cout << " => ";
        printArray(data, n);
    }else if(method == "desc"){
        cout << " => ";
        printArrayDesc(data, n);
    }


    return 0;
}
