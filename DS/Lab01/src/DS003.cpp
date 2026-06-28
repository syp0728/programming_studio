#include <iostream>

using namespace std; 

int main() {
    int month, day; 
    int day_count = 0; 
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    cin >> month >> day;

    for(int i=1; i<month; i++){
        day_count += days[i];
    }

    day_count += day; 

    cout << day_count << endl; 

    return 0;
}