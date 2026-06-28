#include <iostream>

using namespace std; 

struct Menu {
    string name; 
    int price; 
};

struct Cafe {
    string name; 
    int count; 
    Menu *list;
};


void addCafe(Cafe &r1) {
    cin >> r1.name >> r1.count; 
    r1.list = new Menu[r1.count];

}

void addMenu(Menu &m1) {
    cin >> m1.name >> m1.price; 
}

void displayMenus(Cafe &r1) {
    cout << "==== " << r1.name << " ====" << endl;
    for(int i=0; i<r1.count; i++) {
        cout << r1.list[i].name << " " << r1.list[i].price << endl; 
    }
    cout << "====================" << endl;
}

int main() {
    Cafe c1; 
    addCafe(c1);

    for(int i=0; i<c1.count; i++) {
        addMenu(c1.list[i]);
    }

    displayMenus(c1);

    delete[] c1.list; 
    return 0;
}