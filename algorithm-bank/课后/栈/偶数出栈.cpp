#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {}
    Node(int d) : data(d), next(nullptr) {}
};

bool isOdd(int n){
    return(n % 2);
}

int main(){
    int n, x; cin >> n;
    Node* dummy = new Node(), *r = dummy;
    while(cin >> x){
        Node* s = new Node(x);
        r -> next = s;
        r = s;
    }

    Node* top = dummy -> next;
    delete dummy;

    bool flag = false;
    Node* ttop = nullptr;
    while(top != nullptr){
        if(!isOdd(top -> data)){
            if(flag) cout << " ";
            cout << top -> data;
            flag = true;

            Node* temp = top;
            top = top -> next;
            delete temp;
        }else{
            Node* temp = top;
            top = top -> next;
            temp -> next = ttop;
            ttop = temp;
        }
    }

    if(flag) cout << endl;
    while(ttop != nullptr){
        Node* temp = ttop;
        ttop = ttop -> next;
        temp -> next = top;
        top = temp;
    }

    bool isFirst = true;
    while(top != nullptr){
        if(!isFirst) cout << " ";
        cout << top -> data;
        isFirst = false;
        top = top -> next;
    }

    cout << endl;
    return 0;
}