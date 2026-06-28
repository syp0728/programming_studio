#include <iostream>

using namespace std;

struct Node {
    int score;
    string name;
    Node* next;

    Node(int s, string n) : score(s), name(n), next(nullptr) {}
};

Node* insertionSortLinkedList(Node* head) {
    if (!head || !head->next) return head;

    Node* sorted = nullptr; 

    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next; 

        if (!sorted || sorted->score < current->score) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* search = sorted;
            while (search->next != nullptr && search->next->score >= current->score) {
                search = search->next;
            }
            current->next = search->next;
            search->next = current;
        }

        current = nextNode; 
    }

    return sorted; 
}

int main() {
    int n;
    if (!(cin >> n)) return 0; 

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int score;
        string name;
        cin >> score >> name;

        Node* newNode = new Node(score, name);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    head = insertionSortLinkedList(head);

    Node* curr = head;
    int rank = 1;
    while (curr != nullptr) {
        cout << rank << "> " << curr->score << " " << curr->name << "\n";
        rank++;
        
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }

    return 0;
}