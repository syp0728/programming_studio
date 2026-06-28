#include <iostream>

using namespace std; 

void insertionsort(int *list, int s){
    for(int i = 0; i < s - 1; i++){
        int key = list[i+1];
        int j = i; 

        while(j >= 0 && list[j] < key){
            list[j+1] = list[j];
            j--;
        }
        list[j+1] = key;
    }
}

void print(int *list, int s){
    for(int i = 0; i < s; i++){
        cout << list[i] << " "; 
    }
    cout << "\n"; 
}


int main(){
    int size; 
    if (!(cin >> size)) return 0; 

    int *list = new int[size];
    for(int i = 0; i < size; i++){
        cin >> list[i]; 
    }

    insertionsort(list, size); 

    print(list, size); 

    delete[] list;
    return 0; 
}