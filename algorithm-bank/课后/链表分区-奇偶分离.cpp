#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d = 0) : data(d), next(nullptr) {}
};

int main() {
    int n;
    Node* head = new Node();
    Node* r = head;

    while (cin >> n && n != -1) {
        r->next = new Node(n);
        r = r->next;
    }

    if (head->next == nullptr || head->next->next == nullptr) {
        Node* cur = head->next;
        bool isFirst = true;
        while (cur != nullptr) {
            if (!isFirst) cout << " ";
            cout << cur->data;
            isFirst = false;
            cur = cur->next;
        }
        cout << endl;
        return 0;
    }

    Node* odd = head->next;
    Node* even = odd->next;
    Node* evenHead = even; 

    while (even != nullptr && even->next != nullptr) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenHead;

    Node* p = head->next;
    bool isFirst = true;
    while (p != nullptr) {
        if (!isFirst) cout << " ";
        cout << p->data;
        isFirst = false;
        p = p->next;
    }
    cout << endl;

    return 0;
}