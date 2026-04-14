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
    Node* h1 = new Node(), *h2 = new Node(), 
    *r1 = h1, *r2 = h2;
    while(cin >> n){
        if(n == -1) break;
        Node* s = new Node(n);
        r1 -> next = s;
        r1 = s;
    }
    while(cin >> n){
        if(n == -1) break;
        Node* s = new Node(n);
        r2 -> next = s;
        r2 = s;
    }

    Node* ahead = new Node(), *r = ahead;
    Node* p1 = h1 -> next, *p2 = h2 -> next;
    while(p1 != nullptr && p2 != nullptr){
        if(p1 -> data <= p2 -> data){
            r -> next = p1;
            p1 = p1 -> next;
        }else{
            r -> next = p2;
            p2 = p2 -> next;
        }
        r = r -> next;
    }

    if (p1) r->next = p1;
    else if (p2) r->next = p2;

    Node* p = ahead -> next;
    bool isFirst = true;
    while(p != nullptr){
        if(!isFirst) cout << " ";
        cout << p -> data;
        isFirst = false;
        p = p -> next;
    }

    cout << endl;
    return 0;
}

/*
并集逻辑：
while (p1 != nullptr && p2 != nullptr) {
    if (p1->data < p2->data) {
        r->next = p1;
        p1 = p1->next;
        r = r->next;
    } else if (p1->data > p2->data) {
        r->next = p2;
        p2 = p2->next;
        r = r->next;
    } else { // p1->data == p2->data
        r->next = p1;    // 只取 p1
        p1 = p1->next;   // p1 后移
        p2 = p2->next;   // p2 也必须后移！跳过这个重复的值
        r = r->next;
    }
}
// 收尾逻辑：并集需要把剩下的全部接上
if (p1) r->next = p1;
if (p2) r->next = p2;
*/

/*交集逻辑：
while (p1 != nullptr && p2 != nullptr) {
    if (p1->data < p2->data) {
        p1 = p1->next; // p1 太小了，往后找
    } else if (p1->data > p2->data) {
        p2 = p2->next; // p2 太小了，往后找
    } else { // p1->data == p2->data
        r->next = p1;  // 找到了共同项！
        r = r->next;
        p1 = p1->next;
        p2 = p2->next;
    }
}
// 收尾逻辑：交集不需要收尾！
r->next = nullptr; // 【关键】最后一定要封底，否则后面会带着旧链表的尾巴
*/

/*
sstream实现：
string line1, line2;
if(getline(cin, line1)){
    istringstream iss(line1);
    while(iss >> n) { // 存入链表1  }
}
if(getline(cin, line2)){
    istringstream iss(line2);
    while(iss >> n) { // 存入链表2  }
}
*/