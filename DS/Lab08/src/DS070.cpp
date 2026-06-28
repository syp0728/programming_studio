#include <iostream>

using namespace std; 

void swap(int &a, int &b){
    int temp = a; 
    a = b; 
    b = temp; 
}

void print(int *list, int s){
    for(int i=0; i<s; i++){
        cout << list[i] << " "; 
    }
    cout << endl; 
}

void bubblesort(int *list, int s){
    for(int j=s-1; j>0; j--){
        bool swapped = false; 
        for(int i=0; i<j; i++){
            if(list[i] > list[i+1]){
                swap(list[i], list[i+1]);
                swapped = true; 
            }
        }
        if(!swapped){ break; }
    }
}

void selectionsort(int *list, int s){
    for(int i=0; i<s-1; i++){
        int min_i = i; 
        for(int j=i+1; j<s; j++){
            if(list[j] < list[min_i]){
                min_i = j; 
            }
        }
        if(min_i != i) swap(list[i], list[min_i]);
    }
}


void insertionsort(int *list, int s){
    for(int i=0; i<s-1; i++){
        int key = list[i+1];
        int j = i; 

        while(j >= 0 && list[j] > key){
            list[j+1] = list[j];
            j--;
        }

        list[j+1] = key;

        
        // for(; j>=0; j--){
        //     if(list[j] <= key)
        //         list[j+1] = list[j];
        //     else
        //         break;
        // }
    }
}

int partition(int *list, int left, int right){
    int pivot = list[right];
    int i = left; 

    for(int j=0; j<right; j++){
        if(list[j] <= pivot){
            swap(list[i], list[j]); 
            i++;
        }
    }
    swap(list[i], list[right]);
    return i; 
}


void quicksort(int *list, int left, int right){
    if(left < right){
        int pivotIndex = partition(list, left, right);

        quicksort(list, left, pivotIndex-1);
        quicksort(list, pivotIndex + 1, right);
    }
}

void merge(int *list, int left, int mid, int right){
    int s = right - left + 1; 
    int *temp = new int[s];

    int i = left; 
    int j = mid + 1; 
    int k = 0; 

    while(i <= mid && j <= right){
        if(list[i] <= list[j])
            temp[k++] = list[i++];
        else   
            temp[k++] = list[j++];
    }

    while(i <= mid)
        temp[k++] = list[i++];

    while(j <= right)
        temp[k++] = list[j++];

    for(int t=0; t<s; t++){
        list[left + t] = temp[t];
    }

    delete[] temp;

}

void mergesort(int *list, int left, int right){   
    if(left <= right)
        return; 
    int mid = left + (right - left) / 2; 

    mergesort(list, left, mid);
    mergesort(list, mid + 1, right);

    merge(list, left, mid, right);
}


int main(){
    int list[] = {10, 20, 3, 13, 55};
    int size = sizeof(list) / sizeof(list[0]);

    print(list, size);
    bubblesort(list, size); 
    print(list, size);

    selectionsort(list, size);
    print(list, size); 

    insertionsort(list, size);
    print(list, size); 

    return 0; 

}
