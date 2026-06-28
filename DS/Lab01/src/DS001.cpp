#include <iostream>

using namespace std;

int main() {
    int height, weight;
    double bmi;

    if (!(cin >> height >> weight)) return 0;


    double heightM = height / 100.0;
    bmi = weight / (heightM * heightM);

    if (bmi >= 25) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

}


// int n = 4; 
// int *num = new int[n];

// delete[] num; 
// return 0;