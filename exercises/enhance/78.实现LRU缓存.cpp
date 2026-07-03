#include <iostream>
#include <unordered_map>
using namespace std;

struct node {
    int data;
    node* next, *prev;
    node(int d = 0) : data(d), next(nullptr), prev(nullptr) {}
};

int main() {
    int n, m; cin >> n >> m;
    unordered_map<int, node*> pos;
    unordered_map<int, int> mp;

    node* head = new node(), *tail = new node();
    head -> next = tail;
    tail -> prev = head;
    while(m--) {
        string op; cin >> op;
        if(op == "PUT") {
            int k, v; cin >> k >> v;
            if(mp.find(k) != mp.end()) {
                mp[k] = v;

                node* p = pos[k];

                p -> prev -> next = p -> next;
                p -> next -> prev = p -> prev;
                p -> next = head -> next;
                p -> prev = head;
                head -> next -> prev = p;
                head -> next = p;
            } else {
                if(mp.size() == n) {
                    node* temp = tail -> prev;
                    tail -> prev = temp -> prev;
                    tail -> prev -> next = tail;
                    int d = temp -> data;
                    mp.erase(d);
                    pos.erase(d);
                    delete temp;
                }
                
                mp.insert({k, v});
                node* s = new node(k);
                pos.insert({k, s});
                s -> next = head -> next;
                head -> next -> prev = s;
                head -> next = s;
                s -> prev = head;
            }
        } else if(op == "GET") {
            int k; cin >> k;
            if(pos.find(k) == pos.end()) cout << -1 << endl;
            else {
                cout << mp[k] << endl;

                node* p = pos[k];

                p -> prev -> next = p -> next;
                p -> next -> prev = p -> prev;
                p -> next = head -> next;
                p -> prev = head;
                head -> next -> prev = p;
                head -> next = p;
            }
        }
    }

    return 0;
}