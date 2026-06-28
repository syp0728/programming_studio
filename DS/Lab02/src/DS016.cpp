#include <iostream>
#include <string>

using namespace std;

string findPrefix(string* words, int n) {
    if (n == 0) return "?";
    
    string base = words[0];
    string prefix = "";
    
    for (int i = 0; i < base.length(); i++) {
        char c = base[i];
        
        for (int j = 1; j < n; j++) {
            if (i >= words[j].length() || words[j][i] != c) {
                return (prefix == "") ? "?" : prefix;
            }
        }
        prefix += c;
    }
    
    return (prefix == "") ? "?" : prefix;
}

int main() {
    int n = 3; 
    
    string* words = new string[n];

    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    string result = findPrefix(words, n);

    cout << result << endl;

    delete[] words;
    return 0;
}