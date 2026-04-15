#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d = 0) : data(d), next(nullptr) {}
};

Node* ReverseList(Node* curr){
    if(curr == nullptr || curr -> next == nullptr) return curr;
    Node* NewHead = ReverseList(curr -> next);
    curr -> next -> next = curr;
    curr -> next = nullptr;
    return NewHead;
}

int main(){
    int n; Node* hh = new Node(), *r = hh;
    while(cin >> n && n != -1){
        Node* s = new Node(n);
        r -> next = s;
        r = s;
    }
    Node* h = ReverseList(hh -> next);

    Node* p = h;
    bool isFirst = true;
    while(p != nullptr){
        if(!isFirst) cout << " ";
        cout << p -> data;
        isFirst = false;
        p = p -> next;
    }

    cout << endl;
    return 0;
}