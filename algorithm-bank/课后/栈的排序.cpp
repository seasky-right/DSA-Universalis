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
    cin >> n;
    Node* head = new Node();
    for(int i = 0; i < n; ++i){
        int a; cin >> a;
        Node*s = new Node(a);
        s -> next = head -> next;
        head -> next = s;
    }

    Node* ahead = new Node();
    while(head -> next != nullptr){
        Node*s = head -> next;
        head -> next = s -> next;
        while(ahead -> next != nullptr &&
            ahead -> next -> data < s -> data){
            Node* t = ahead -> next;
            ahead -> next = t -> next;
            t -> next = head -> next;
            head -> next = t;
        }
        s -> next = ahead -> next;
        ahead -> next = s;
    }

    Node* p = ahead -> next;
    bool isFirst = true;
    while(p != nullptr){
        if(!isFirst) cout << " ";
        cout << p -> data;
        isFirst = false;
        p = p -> next;
    }
    return 0;
}

//if-else分支跳出后不会继续运行。

//注意条件顺序同时也是判断的数据。