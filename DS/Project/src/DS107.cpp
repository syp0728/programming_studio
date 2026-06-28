#include <iostream>

using namespace std;

void insertionsort(int *list, int s) {
    for (int i = 0; i < s - 1; i++) {
        int key = list[i + 1];
        int j = i;

        while (j >= 0 && list[j] < key) {
            list[j + 1] = list[j];
            j--;
        }
        list[j + 1] = key;
    }
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        int totalSize = n + m;
        int *allScores = new int[totalSize];

        for (int i = 0; i < totalSize; i++) {
            cin >> allScores[i];
        }

        insertionsort(allScores, totalSize);

        for (int i = 0; i < totalSize; i++) {
            cout << allScores[i] << " ";
        }
        cout << "\n";
        break;

        delete[] allScores;
    }

    return 0;
}