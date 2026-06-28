#include <iostream>

using namespace std; 

int main() {
    string input; 
    cin >> input; 
    
    int count = 0; 

    for(int i=0; i<20; i++){
        char target = input[i]; 

        if(target == 'I'){
            count += 1; 
        }else if(target == 'V'){
            count += 5; 
        }else if(target == 'X'){
            count += 10; 
        }else if(target == 'L'){
            count += 50;
        }else if(target == 'C'){
            count += 100; 
        }else if(target == 'D'){
            count += 500;
        }else if(target == 'M'){
            count += 1000;
        }
    }

    cout << count << endl; 

    return 0;
}