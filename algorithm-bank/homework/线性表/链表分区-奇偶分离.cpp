#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d = 0) : data(d), next(nullptr) {}
};

int main() {
    Node* head = new Node(), *r = head;
    int n;
    while(cin >> n && n != -1){
        r -> next = new Node(n);
        r = r -> next;
    }

    Node* odd = head -> next;
    Node* even = odd -> next;
    Node* evenhead = even;

    while(even != nullptr && even -> next != nullptr){
        odd -> next = even -> next;
        odd = odd -> next;
        even -> next = odd -> next;
        even = even -> next;
    }
    odd -> next = evenhead;

    Node* p = head -> next;
    while(p != nullptr){
        cout << p -> data <<(p -> next ? " " : "");
        p = p -> next;
    }

    cout << endl;
    return 0;
}