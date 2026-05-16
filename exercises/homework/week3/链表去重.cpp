#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

int main(){
    Node* head = new Node, *r = head;
    head -> data = 0;
    head -> next = nullptr;
    int n;
    while(cin >> n){
        if(n == -1) break;
        Node* s = new Node;
        s -> data = n;
        s -> next = nullptr;
        r -> next = s;
        r = s;
    }

    Node* curr = head -> next;
    while(curr != nullptr && curr -> next != nullptr){
        if(curr -> data == curr -> next -> data){
            Node* temp = curr -> next;
            curr -> next = curr -> next -> next;
            delete temp;
        }else{
            curr = curr -> next;
        }
    }

    Node* p = head -> next;
    bool isFirst = true;
    while(p != nullptr){
        if(!isFirst) cout << " ";
        cout << p -> data;
        p = p -> next;
        isFirst = false;
    }
    cout << endl;
    return 0;
}