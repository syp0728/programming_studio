#include <iostream>

using namespace std; 


void printinfo(int *num, int size) {
    // 출력
    int max = num[0];
    int total = 0;

    for(int i=0; i<size; i++){

        total += num[i];

        if(num[i] > max) {max = num[i];}
    }

    cout << total << " " << max << endl; 
}

int main() {
    int size; 
    cin >> size; 

    int *list = new int[size];

    // 입력
    for(int i=0; i<size; i++) {
        cin >> list[i];
    }

    printinfo(list, size);


    delete[] list; 
    return 0;
}