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

int main(){
    int n, k;
    if (!(cin >> n >> k)) return 0;

    int *scores = new int[n];
    for(int i = 0; i < n; i++){
        cin >> scores[i]; 
    }

    insertionsort(scores, n);

    cout << scores[k - 1] << "\n";

    delete[] scores;

    return 0; 
}