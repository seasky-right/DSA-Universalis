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

int ASL() {
    int totalLength = 0, totalNodes = 0;

    for(int i = 0; i < 11; ++i) {
        HNode* curr = table[i];
        int length = 0, count = 0;
        while(curr) {
            count++; totalNodes++;
            length += count;
            curr = curr -> next;
        }
        totalLength += length;
    }

    if(totalNodes == 0) return 0;
    return totalLength / totalNodes;
}

int main() {
    int n; cin >> n;
    for(int i = 0; i < n; ++i) {
        int k, v; cin >> k >> v;
        CreateHash(k, v);
    }

    cout << ASL() << endl;
    return 0;
}
