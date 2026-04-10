#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d = 0) : data(d), next(nullptr) {}
};

Node* reverseRecursive(Node* curr) {
    if (curr == nullptr || curr->next == nullptr) {
        return curr;
    }
    
    Node* newHead = reverseRecursive(curr->next);
    
    curr->next->next = curr;
    curr->next = nullptr;
    
    return newHead;
}

int main() {
    int n;
    Node* head = new Node();
    Node* r = head;

    while (cin >> n && n != -1) {
        r->next = new Node(n);
        r = r->next;
    }

    if (head->next != nullptr) {
        head->next = reverseRecursive(head->next);
    }

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