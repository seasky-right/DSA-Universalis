#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {}
    Node(int d) : data(d), next(nullptr) {}
};

int main(){
    int n, m;
    cin >> n >> m;
    Node* head = new Node(1), *r = head;
    for(int i = 2; i <= n; ++i){
        Node* s = new Node(i);
        r -> next = s;
        r = s;
    }
    r -> next = head;

    Node* p = r;
    while(p -> next != p){
        for(int i = 0; i < m - 1; ++i){
            p = p -> next;
        }
        Node* target = p -> next;
        cout << target -> data << " ";
        p -> next = target -> next;
        delete target;
    }

    cout << p -> data << endl;
    return 0;
}