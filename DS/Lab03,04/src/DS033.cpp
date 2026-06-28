#include <iostream>

using namespace std; 

struct Coupon{
    int rank; 
    string name; 
};

typedef struct Coupon coupon; 

class CouponStack{
        int maxsize; 
        int top; 
        coupon *list; 
    public: 
        void initialize(); 
        bool is_empty() const; 
        bool is_full() const; 
        void push (const coupon &c); 
        coupon* pop(); 

        CouponStack(int = 10){
            maxsize = 10; 
            list = new coupon[maxsize]; 
            initialize();
        }
        ~CouponStack(){
            delete[] list; 
        }

        void print();               // stack 전체 출력
        void rprint();              // stack pop하면서 전체출력

};

void CouponStack::initialize(){
    top = -1; 
}

bool CouponStack::is_empty() const{
    return top == -1; 
}
bool CouponStack::is_full() const{
    return top == maxsize - 1; 
}

void CouponStack::push(const coupon &c){
    if(is_full()){
        cout << "CouponStack is full" << endl; 
        return; 
    }
    list[++top] = c; 
}

coupon* CouponStack::pop(){
    if(is_empty()){
        cout << "CouponStack is empty" << endl; 
        return nullptr; 
    }
    return &list[top--]; 
}


void CouponStack::print(){
    for(int i = top; i >= 0; i--){
        cout << list[i].rank << "등 - " << list[i].name << endl; 
    }
}

void CouponStack::rprint(){
    while(!is_empty()){
        coupon* c = pop(); 
        if(c != nullptr){
            cout << c->rank << "등 - " << c->name << endl; 
        }
    }
}

int main() {
    int size; 
    cin >> size; 

    CouponStack stack(size);
    char cmd; 

    while(cin >> cmd){
        if(cmd == 'q') break;
        else if(cmd == '+') {
            coupon c;
            cin >> c.rank;
            cin.ignore(); 
            getline(cin, c.name);
            stack.push(c);
        }else if(cmd == '-') {
            coupon* c = stack.pop();
            if(c != nullptr){
                cout << c->rank << "등 - " << c->name << endl; 
            }else{
                cout << "Stack is empty" << endl;
            }
        }
    }

    return 0;
}