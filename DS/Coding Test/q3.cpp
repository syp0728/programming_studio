#include <iostream>
using namespace std;

#define MAX_SIZE = 5; 

class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};
class LLQ
{
    Node *front, *rear;

public:
    LLQ() : front(nullptr), rear(nullptr) {}
    ~LLQ() { clear(); }

    bool isEmpty()
    {
        return front == nullptr;
    }

    void enqueue(int val)
    {
        Node *newnode = new Node(val);
        if (isEmpty())
        {
            rear = newnode;
            front = newnode;
        }
        else
        {
            rear->next = newnode;
            rear = newnode;
        }
    }

    /*
    1. front 노드 제거 및 반환
    2. front 갱신 처리
    3. 비어있는 큐 처리
    4. 메모리 누수 없이 처리
     */
    void dequeue()
    {
        if(isEmpty())return; 
        Node* temp = front;
        front = front->next;
        delete temp;
        if(isEmpty()) rear = nullptr; 
    }

    void printAll()
    {
        if (isEmpty())
            return;
        Node *node = front;
        while (node)
        {
            cout << node->data << " -> ";
            node = node->next;
        }
        cout << endl;
    }
    int frontItem()
    {
        if(isEmpty()) return -1;
        return front->data;
    }

    int rearItem()
    {
        if(isEmpty()) return -1;
        return rear->data; 
    }

    void clear()
    {
        while(!isEmpty())dequeue();

    }
};
int main()
{
    LLQ q;
    int choice, flag = 1, value;
    while (flag == 1)
    {
        cout << "\n1.Enqueue 2.Dequeue 3.Show front 4.Show rear 5.Display all 6.Clear 7.Quit >> ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter Value: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            cout << "Front data is " << q.frontItem() << endl;
            break;
        case 4: 
            cout << "Rear data is " << q.rearItem() << endl; 
        case 5:
            q.printAll();
            break;        
        case 6: 
            q.clear();
            break;
        case 7:
            flag = 0;
            break;
        }
    }
    return 0;
}