#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct node {
    int data;
    node* lchild, *rchild;

    node(int d) : data(d), lchild(nullptr), rchild(nullptr) {}
};

node* nodes[10005] = {nullptr};
node* CreateTree(int n) {
    string pr, lr, rr; 
    if(!(cin >> pr >> lr >> rr))
        return nullptr;
    int roo = stoi(pr);
    nodes[roo] = new node(roo);
    node* root = nodes[roo];

    if(lr == "#") root -> lchild = nullptr;
    else {
        int l = stoi(lr);
        nodes[l] = new node(l);
        root -> lchild = nodes[l];
    }
    if(rr == "#") root -> rchild = nullptr;
    else {
        int r = stoi(rr);
        nodes[r] = new node(r);
        root -> rchild = nodes[r];
    }

    for(int i = 1; i < n; ++i) {
        string pc, lc, rc; cin >> pc >> lc >> rc;

        int p = stoi(pc);
        if(!nodes[p]) nodes[p] = new node(p);

        if(lc == "#") nodes[p] -> lchild = nullptr;
        else {
            int l = stoi(lc);
            if(!nodes[l]) nodes[l] = new node(l);
            nodes[p] -> lchild = nodes[l];
        }

        if(rc == "#") nodes[p] -> rchild = nullptr;
        else {
            int r = stoi(rc);
            if(!nodes[r]) nodes[r] = new node(r);
            nodes[p] -> rchild = nodes[r];
        }
    }

    return root;
}

int findLongest(node* root) {
    if(!root) return 0;
    int left = findLongest(root -> lchild);
    int right = findLongest(root -> rchild);

    return max(left, right) + 1;
}

int main() {
    int n; cin >> n;
    node* root = CreateTree(n);

    if(!root) {
        cout << 0 << endl;
        return 0;
    
    }

    cout << findLongest(root) - 1 << endl;

    return 0;
}