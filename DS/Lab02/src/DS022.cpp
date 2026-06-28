#include <iostream>

using namespace std; 

class Student {
    private: 
        int total() const;
        const char* PF(int score) const; 
    public: 
        char name[50]; 
        int *score; 

        void print() const {
            cout << "\n[" << name << "] " << endl;
            cout << "LC - " << PF(score[0]) << endl;
            cout << "RC - " << PF(score[1]) << endl;
            cout << "Total - " << total() << endl;
        }
};

int Student::total() const {
    return score[0] + score[1];
}

const char* Student::PF(int s) const {
    if(s >= 350) return "Pass";
    else return "Fail";
}

int main() {
    Student s1; 

    s1.score = new int[2];
    
    cin.getline(s1.name, 50);

    const char* labels[] = {"LC", "RC"};
    for(int i=0; i<2; i++) {
        while(true) {
            cout << labels[i] << "> ";
            cin >> s1.score[i];
            
            if(s1.score[i] >= 0 && s1.score[i] <= 495) {
                break; 
            }
        }
    }

    s1.print();

    delete[] s1.score;
    return 0; 
}