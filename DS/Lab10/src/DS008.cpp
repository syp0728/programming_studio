#include <iostream>
#include <string>

using namespace std;

int getNum(char c) {
    if (c == 'I') return 1;
    if (c == 'V') return 5;
    if (c == 'X') return 10;
    if (c == 'L') return 50;
    if (c == 'C') return 100;
    if (c == 'D') return 500;
    if (c == 'M') return 1000;
    return 0;
}

int main() {
    string input;
    cin >> input; 

    int total = 0;
    int len = input.length();

    // 문자열 길이가 20을 넘을 수 X
    if (len > 20) len = 20;

    for (int i = 0; i < len; i++) {
        int current = getNum(input[i]);
        
        // 다음 문자가 있고, 다음 문자의 값이 현재보다 크면 getNum
        if (i + 1 < len && current < getNum(input[i + 1])) {
            total -= current;
        } else {
            total += current;
        }
    }

    cout << total << endl;

    return 0;
}