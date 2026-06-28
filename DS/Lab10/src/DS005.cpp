#include <iostream>

using namespace std; 

int main() {
    string input;
    getline(cin, input);

    int myArray[26] = {0};

    for(int i=0; i<input.length(); i++){

        // 대문자인 경우 소문자로 변환
        char target = input[i];

        if(target >= 'A' && target <= 'Z'){
            target = target + 32; 
        }

        myArray[target - 'a']++;  // 'a'를 빼야 0~25 사이의 인덱스가 나옴
    }

    for(int i=0; i<26; i++){
        if(myArray[i] > 0){
            cout << (char)(i + 65) << ": "<< myArray[i] << endl;    // 출력할 때 65('A')를 더하면 대문자로 출력됨
        }
    }

    return 0; 



}