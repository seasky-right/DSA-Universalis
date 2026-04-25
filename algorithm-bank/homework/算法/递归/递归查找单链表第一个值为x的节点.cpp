#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node() : data(), next(nullptr) {}
    Node(int d) : data(d), next(nullptr) {}
};

int getNo(Node* p, int x){
    if(p == nullptr) return -1;
    if(p -> data == x) return 0;

    int ans = getNo(p -> next, x);
    if(ans == -1) return -1;
    else return 1 + ans;
}

int main(){
    int n; cin >> n;
    Node* hh = new Node(), *r = hh;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        r -> next = new Node(x);
        r = r -> next;
    }
    int m; cin >> m;

    cout << getNo(hh -> next, m) << endl;
    return 0;
}