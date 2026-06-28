#include <iostream>

using namespace std;

class Product {
private:
    string name;         
    int price;    
    int sale;     
    string size;         
    string company;  

public:
    Product() {
        price = 0;
        sale = 0;
    }

    int getSalePrice() const {
        return price * (100 - sale) / 100;
    }

    void inputProduct() {
        cin.ignore(); 
        
        getline(cin, name);
        
        cin >> price >> sale >> size >> company;
    }

    void printProduct() const {
        if (sale == 0) {
            cout << getSalePrice() << " (0%) " 
                 << name << " " << size << " " << company << endl;
        } else {
            cout << getSalePrice() << " (-" << sale << "%) " 
                 << name << " " << size << " " << company << endl;
        }
    }
};

int main() {
    Product* sList[100];
    int pCount = 0; 
    int menu;

    while (true) {
        cout << "1. Add  2.List 3.Quit > ";
        cin >> menu;

        if (menu == 1) {
            sList[pCount] = new Product(); 
            sList[pCount]->inputProduct();
            pCount++;
        } 
        else if (menu == 2) {
            for (int i = 0; i < pCount; i++) {
                sList[i]->printProduct();
            }
        } 
        else if (menu == 3) {
            for (int i = 0; i < pCount; i++) {
                delete sList[i];
            }
            break;
        }
    }

    return 0;
}