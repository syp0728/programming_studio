#include <iostream>

using namespace std; 

int step = 1; // 정렬 단계 출력을 위한 전역 카운터

// 값 교환 함수
void swap(int &a, int &b){
    int temp = a; 
    a = b; 
    b = temp; 
}

// 현재 배열의 상태를 출력하는 함수
void print(int *list, int s){
    for(int i=0; i<s; i++){
        cout << list[i] << " "; 
    }
    cout << "\n"; 
}

// 원본 배열을 복사해오는 유틸리티 함수
void resetList(int *src, int *dest, int s) {
    for(int i=0; i<s; i++) {
        dest[i] = src[i];
    }
    step = 1; // 단계 초기화
}

// 1. 버블 정렬
void bubblesort(int *list, int s){
    for(int j=s-1; j>0; j--){
        bool swapped = false; 
        for(int i=0; i<j; i++){
            if(list[i] > list[i+1]){
                swap(list[i], list[i+1]);
                swapped = true; 
            }
        }
        cout << "  [Pass " << step++ << "]: "; print(list, s);
        if(!swapped){ break; }
    }
}

// 2. 선택 정렬
void selectionsort(int *list, int s){
    for(int i=0; i<s-1; i++){
        int min_i = i; 
        for(int j=i+1; j<s; j++){
            if(list[j] < list[min_i]){
                min_i = j; 
            }
        }
        if(min_i != i) swap(list[i], list[min_i]);
        cout << "  [Pass " << step++ << "]: "; print(list, s);
    }
}

// 3. 삽입 정렬
void insertionsort(int *list, int s){
    for(int i=0; i<s-1; i++){
        int key = list[i+1];
        int j = i; 

        while(j >= 0 && list[j] > key){
            list[j+1] = list[j];
            j--;
        }
        list[j+1] = key;
        cout << "  [Pass " << step++ << "]: "; print(list, s);
    }
}

// 4. 퀵 정렬용 파티션 및 추적
int partition(int *list, int left, int right, int total_size){
    int pivot = list[right];
    int i = left; 

    // 기존 소스 버그 교정: j가 0부터가 아니라 left부터 탐색해야 부분 배열 정렬이 정상 작동합니다.
    for(int j=left; j<right; j++){
        if(list[j] <= pivot){
            swap(list[i], list[j]); 
            i++;
        }
    }
    swap(list[i], list[right]);
    return i; 
}

void quicksort(int *list, int left, int right, int total_size){
    if(left < right){
        int pivotIndex = partition(list, left, right, total_size);

        // 피벗을 기준으로 구역이 나뉜 상태를 출력
        cout << "  [Pass " << step++ << "] (Pivot=" << list[pivotIndex] << "): "; 
        print(list, total_size);

        quicksort(list, left, pivotIndex-1, total_size);
        quicksort(list, pivotIndex + 1, right, total_size);
    }
}

// 5. 합병 정렬용 머지 및 추적
void merge(int *list, int left, int mid, int right, int total_size){
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

    // 조각난 서브 배열들이 합쳐진 상태를 전체 배열 관점에서 출력
    cout << "  [Merge Pass " << step++ << "] (Range: " << left << "~" << right << "): ";
    print(list, total_size);
}

void mergesort(int *list, int left, int right, int total_size){   
    // 기존 소스 버그 교정: left <= right 이면 시작하자마자 튕겨 나가므로 left >= right 로 수정되어야 합니다.
    if(left >= right)
        return; 
        
    int mid = left + (right - left) / 2; 

    mergesort(list, left, mid, total_size);
    mergesort(list, mid + 1, right, total_size);

    merge(list, left, mid, right, total_size);
}


int main(){
    int size;
    cout << "배열의 크기를 입력하세요: ";
    if (!(cin >> size) || size <= 0) return 0;

    int *original = new int[size];
    int *list = new int[size];

    cout << size << "개의 배열 원소를 공백으로 구분하여 입력하세요:\n";
    for(int i=0; i<size; i++) {
        cin >> original[i];
    }
    cout << "\n";

    // --- (1) 버블 정렬 ---
    resetList(original, list, size);
    cout << "=== Bubble Sort ===" << endl;
    cout << "  [Initial]: "; print(list, size);
    bubblesort(list, size); 
    cout << endl;

    // --- (2) 선택 정렬 ---
    resetList(original, list, size);
    cout << "=== Selection Sort ===" << endl;
    cout << "  [Initial]: "; print(list, size);
    selectionsort(list, size);
    cout << endl;

    // --- (3) 삽입 정렬 ---
    resetList(original, list, size);
    cout << "=== Insertion Sort ===" << endl;
    cout << "  [Initial]: "; print(list, size);
    insertionsort(list, size);
    cout << endl;

    // --- (4) 퀵 정렬 ---
    resetList(original, list, size);
    cout << "=== Quick Sort ===" << endl;
    cout << "  [Initial]: "; print(list, size);
    quicksort(list, 0, size - 1, size);
    cout << endl;

    // --- (5) 합병 정렬 ---
    resetList(original, list, size);
    cout << "=== Merge Sort ===" << endl;
    cout << "  [Initial]: "; print(list, size);
    mergesort(list, 0, size - 1, size);
    cout << endl;

    delete[] original;
    delete[] list;
    return 0; 
}