#include <iostream>

using namespace std; 

struct Product {
    string name; 
    int price; 
    string company; 
};

void input(Product *plist, int size) {
    for(int i=0; i<size; i++) {
        cin >> plist[i].name >> plist[i].price >> plist[i].company; 
    }
}

string touppercase(string str) {
    for(int i=0; i<str.size(); i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - ('a' - 'A');
        }
    }
    return str; 
}

bool compareProduct(Product p1, Product p2) {
    if(touppercase(p1.name) == touppercase(p2.name) && p1.price == p2.price) {
        return true; 
    }
    return false; 
}




int main() {
    int size = 2; 
    Product *plist = new Product[size];


    // 입력
    input(plist, size);

    // 비교
    if(compareProduct(plist[0], plist[1])) {
        // equal
        cout << plist[0].name << " is equal" << endl;    
    }
    else{
        // not equal
        cout << plist[0].name << " and " << plist[1].name << " are not equal." << endl; 
    
    }



    delete[] plist; 
    return 0;
}