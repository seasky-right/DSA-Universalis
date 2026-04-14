#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node() : data(0),next(nullptr) {}
    Node(int d) : data(d),next(nullptr) {}
};

int main(){
    int k, n;
    if (!(cin >> k)) return 0;
    Node* head = new Node(), *r = head;
    while(cin >> n){
        if(n == -1) break;
        Node* s = new Node(n);
        r -> next = s;
        r = s;
    }

    if (!head -> next) {
        cout << -1 << endl;
        return 0; 
    }
    Node* slow = head -> next, *fast = head -> next;
    for(int i = 0; i < k - 1; ++i){
        if(fast -> next == nullptr){
            cout << -1 << endl;
            return 0;
        }
        fast = fast -> next;
    }

    while(fast -> next != nullptr){
        slow = slow -> next;
        fast = fast -> next;
    }

    cout << slow -> data << endl;
    return 0;
}