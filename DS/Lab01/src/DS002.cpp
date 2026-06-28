#include <iostream>
#include <cmath> 
#include <cstdio>

using namespace std;

int main() {
    float x1, y1; // 첫 번째 좌표
    float x2, y2; // 두 번째 좌표
    float distance;

    cin >> x1 >> y1;
    cin >> x2 >> y2;

    distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    printf("%.1f\n", distance);

    return 0;
}