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


int main() {
    string s;
    getline(cin, s);

    string both = rtrim(ltrim(s));
    cout <<  both << endl;

    return 0;
}