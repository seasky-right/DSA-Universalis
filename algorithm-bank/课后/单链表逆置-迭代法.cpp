#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d = 0) : data(d), next(nullptr) {}
};

int main() {
    int n;
    Node* head = new Node();
    Node* r = head;

    while (cin >> n && n != -1) {
        r->next = new Node(n);
        r = r->next;
    }

    Node* prev = nullptr;
    Node* curr = head->next; 
    Node* nextTemp = nullptr;

    while (curr != nullptr) {
        nextTemp = curr->next; 
        curr->next = prev;     
        prev = curr;           
        curr = nextTemp;       
    }

    head->next = prev;

    Node* p = head->next;
    bool isFirst = true;
    while (p != nullptr) {
        if (!isFirst) cout << " ";
        cout << p->data;
        isFirst = false;
        p = p->next;
    }
    cout << endl;

    return 0;
}