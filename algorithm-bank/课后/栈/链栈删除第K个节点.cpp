#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node() : data(), next(nullptr) {}
    Node(int d) : data(d), next(nullptr) {}
};

int main() {
    int n;
    if (!(cin >> n)) return 0;

    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        Node* s = new Node(val);
        if (head == nullptr) {
            head = s;
            tail = s;
        } else {
            tail->next = s;
            tail = s;
        }
    }

    int k;
    cin >> k;

    bool isError = false;
    int deletedVal = -1;

    if (k <= 0 || k > n) {
        isError = true;
    } else {
        if (k == 1) {
            Node* temp = head;
            deletedVal = temp->data;
            head = head->next;
            delete temp;
        } else {
            Node* prev = head;
            for (int i = 1; i < k - 1; ++i) {
                prev = prev->next;
            }
            Node* target = prev->next;
            deletedVal = target->data;
            prev->next = target->next;
            delete target;
        }
        n--;
    }

    if (isError) {
        return 0;
    } else {
        cout << deletedVal << endl;
    }

    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << (curr->next ? " " : "");
        curr = curr->next;
    }
    cout << endl;

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
