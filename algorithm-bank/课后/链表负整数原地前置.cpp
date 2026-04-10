#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {}
    Node(int d) : data(d), next(nullptr) {}
};

int main(){
    int n;
    if(!(cin >> n)) return 0;
    Node* head = new Node(), *r = head;
    for(int i = 0; i < n; ++i){
        int a;
        cin >> a;
        Node* s = new Node(a);
        r -> next = s;
        r = s;
    }

    Node* rr = head;
    while(rr -> next != nullptr && rr -> next -> data < 0){
        rr = rr -> next;
    }
    Node* p = rr;
    while(p -> next != nullptr){
        if(p -> next -> data < 0){
            Node *temp = p -> next;
            p -> next = temp -> next;
            temp -> next = rr -> next;
            rr -> next = temp;
            rr = temp;
        }else{
            p = p -> next;
        }
    }

    Node* q = head -> next;
    bool isFirst = true;
    while(q != nullptr){
        if(!isFirst) cout << " ";
        cout << q -> data;
        isFirst = false;
        q = q -> next;
    }
    cout << endl;
    return 0;

}