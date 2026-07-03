#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node(int d) : data{d}, next(nullptr) {}
};

node* merge(node* h1, node* h2) {
    if(!h1) return h2;
    if(!h2) return h1;

    node* head = new node(0);
    node* r = head;

    while(h1 && h2) {
        if(h1 -> data <= h2 -> data) { // 排序不能吃数据
            r -> next = h1;
            h1 = h1 -> next;
        }else {
            r -> next = h2;
            h2 = h2 -> next;
        }
        r = r -> next;
    }
    
    if(h1) r -> next = h1;
    if(h2) r -> next = h2;

    return head -> next;
}

node* MergeSort(node* head) {
    if(!head || !head -> next) return head;
    node* f = head -> next, *s = head;
    while(f && f -> next){
        s = s -> next;
        f = f -> next -> next;
    }
    node* mid = s -> next;
    s -> next = nullptr;

    return merge(MergeSort(head), MergeSort(mid));
}

int main() {
    int x; node* head = nullptr;
    while(1) {
        cin >> x;
        if(x == -1) break;
        node* s = new node(x);
        if(!head) head = s;
        else {
            s -> next = head -> next;
            head -> next = s;
        }
    }

    head = MergeSort(head);

    bool isFirst = true;
    node* p = head;
    while(p) {
        if(!isFirst) cout << " ";
        cout << p -> data;
        isFirst = false;
        p = p -> next;
    }
    cout << endl;

    return 0;
}