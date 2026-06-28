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