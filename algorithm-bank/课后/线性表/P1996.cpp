#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node() : next(nullptr) {}
    Node(int d) : data(d), next(nullptr) {}
};

class Joseph{
public:
    Node* head;
    Node* tail;
    int n, m;
    Joseph(int N, int M) : n(N), m(M), head(nullptr), tail(nullptr) {}

    void create(){
        head = new Node(1);
        tail = head;
        for(int i = 2; i <= n; ++i){
            Node* s = new Node(i);
            tail -> next = s;
            tail = s;
        }
        tail -> next = head;
    }

    void solve(){
        Node* p = head, *pre = tail;
        while(p -> next != p){
            for(int i = 1; i < m; ++i){
                pre = p;
                p = p -> next;
            }
            cout << p -> data << " ";
            Node* temp = p;
            pre -> next = p -> next;
            p = p -> next;
            delete temp;
        }
        cout << p -> data << endl;
        delete p;
        head = tail = nullptr;
    }
};

int main(){
    int N, M;
    cin >> N >> M;
    Joseph joseph(N, M);
    joseph.create();
    joseph.solve();

    return 0;
}