#include <iostream>
#include <string>

using namespace std;

string ltrim(string s) {
    int start = 0;
    int len = s.length();

    while (start < len && isspace(s[start])) {
        start++;
    }

    string result = "";
    for (int i = start; i < len; i++) {
        result += s[i];
    }
    return result;
}

string rtrim(string s) {
    int len = s.length();
    int end = len - 1;

    while (end >= 0 && isspace(s[end])) {
        end--;
    }

    string result = "";
    for (int i = 0; i <= end; i++) {
        result += s[i];
    }
    return result;
}

int count(string s) {
    int count = 0; 
    int i = s.length() - 1;  

    // 공백을 만나기 전까지 반복하며 숫자를 카운트
    while (i >= 0 && s[i] != ' ' && s[i] != '\t') {
        count++;
        i--;
    }
    
    return count;
}

int main() {
    string s;
    getline(cin, s);

    string both = rtrim(ltrim(s));
    cout <<  both << endl;
    cout << count(both) << endl; 

    return 0;
}
