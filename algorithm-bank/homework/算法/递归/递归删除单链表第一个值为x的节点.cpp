#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node() : next(nullptr) {}
    Node(int c) : data(c), next(nullptr) {}
};

Node* deleteX(Node* p, int x){
    if(!p) return nullptr;
    if(p -> data == x){
        Node* temp = p -> next;
        delete p;
        return temp;
    }

    p -> next = deleteX(p -> next, x);
    return p;
}



int main() {
    int n; cin >> n;
    Node* hh = nullptr, * r = nullptr;
    for(int i = 0; i < n; ++i){
        int m; cin >> m;
        Node* s = new Node(m);
        if(!hh) hh = s;
        else r -> next = s;
        r = s;
    }

    int x; cin >> x;
    hh = deleteX(hh, x);

    if(hh == nullptr){
        cout << "NULL" << endl;
    }else{
        Node* p = hh;
        bool isFirst = true;
        while(p){
            if(!isFirst) cout << " ";
            cout << p -> data;
            isFirst = false;
            p = p -> next;
        }
        cout << endl;
    }

    return 0;
}