#include <iostream>

using namespace std; 

void swap(int &a, int &b){
    int temp = a; 
    a = b; 
    b = temp; 
}

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

    int *A = new int[n];
    int *B = new int[n];

    for(int i = 0; i < n; i++) cin >> A[i]; 
    for(int i = 0; i < n; i++) cin >> B[i]; 

    insertionsort(A, n);
    insertionsort(B, n);

    int swap_count = 0; 

    for(int i = 0; i < k; i++) {
        // 내림차순이므로 A의 최솟값은 맨 뒤(n - 1 - i), B의 최댓값은 맨 앞(i)에 위치함
        int a_min_idx = n - 1 - i;
        int b_max_idx = i;

        // B의 가장 큰 값이 A의 가장 작은 값보다 클 때만 교환 수행
        if(A[a_min_idx] < B[b_max_idx]) {
            swap(A[a_min_idx], B[b_max_idx]);
            swap_count++;
        } 
        else {
            // A의 남은 최솟값이 B의 남은 최댓값보다 크거나 같다면 더 이상 교환해도 이득이 없으므로 중단
            break;
        }
    }

    // A 세트 카드들의 최종 총합 계산
    int total_sum = 0; 
    for(int i = 0; i < n; i++) {
        total_sum += A[i];
    }

    cout << swap_count << " " << total_sum << "\n";

    delete[] A;
    delete[] B;

    return 0; 
}