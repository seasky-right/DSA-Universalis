#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d = 0) : data(d), next(nullptr) {}
};

int main() {
    int n; 
    Node* head = new Node(), *r = head;
    while(cin >> n && n != -1){
        r -> next = new Node(n);
        r = r -> next;
    }

    Node* prev = nullptr;
    Node* curr = head -> next;
    Node* nexttemp = nullptr;

    while(curr != nullptr){
        nexttemp = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = nexttemp;
    }

    head -> next = prev;

    Node* p = head -> next;
    while(p != nullptr){
        cout << p -> data << (p -> next ? " " : "");
        p = p -> next;
    }

    cout << endl;
    return 0;
}