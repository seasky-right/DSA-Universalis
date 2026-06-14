#include <iostream>

using namespace std;

const int NULLKEY = -1;
struct HNode {
    int key, data;
    HNode* next;

    HNode(int k, int d) : key(k), data(d), next(nullptr) {}
};

HNode* table[11];
void CreateHash(int k, int v) {
    int d = k % 11;
    HNode* s = new HNode(k, v);

    s -> next = table[d];
    table[d] = s;
}

bool RemoveHash(int k) {
    int d = k % 11;
    HNode* curr = table[d];
    HNode* prev = nullptr;

    while (curr) {
        if (curr->key == k) {
            if (prev) {
                prev->next = curr->next;
            } else {
                table[d] = curr->next;
            }
            delete curr;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    return false;
}

int main() {
    int n; cin >> n;
    
    string op;
    while (cin >> op) {
        if(op == "insert") {
            int k, v; cin >> k >> v;
            CreateHash(k, v);
        }
        else if(op == "remove") {
            int k; cin >> k;
            if(RemoveHash(k)) {
                cout << "Delete successfully" << endl;
            } else {
                cout << "Key not found" << endl;
            }
        }
    }
    return 0;
}
