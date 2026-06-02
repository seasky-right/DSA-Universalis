#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct node {
    int data;
    node* lchild, *rchild;

    node(int d) : data(d), lchild(nullptr), rchild(nullptr) {}
};

node* nodes[10005] = {nullptr};
bool isChild[10005] = {false};
node* CreateTree(int n) {
    for(int i = 0; i < n; ++i) {
        string pc, lc, rc; cin >> pc >> lc >> rc;

        int p = stoi(pc);
        if(!nodes[p]) nodes[p] = new node(p);

        if(lc == "#") nodes[p] -> lchild = nullptr;
        else {
            int l = stoi(lc);
            if(!nodes[l]) nodes[l] = new node(l);
            nodes[p] -> lchild = nodes[l];
            isChild[l] = true;
        }

        if(rc == "#") nodes[p] -> rchild = nullptr;
        else {
            int r = stoi(rc);
            if(!nodes[r]) nodes[r] = new node(r);
            nodes[p] -> rchild = nodes[r];
            isChild[r] = true;
        }
    }

    for(int i = 0; i < 10005; ++i) {
        if(nodes[i]){
            if(!isChild[i])
                return nodes[i];
        }
    }

    return nullptr;
}

int dfs(node* p, int curr_width) {
    if(!p) return -1;
    curr_width = min(curr_width, p -> data);
    if(!p -> lchild && !p -> rchild) return curr_width;
    return max(dfs(p -> lchild, curr_width), dfs(p -> rchild, curr_width));
}

int main() {
    int n; cin >> n;
    node* root = CreateTree(n);
    cout << dfs(root, root -> data) << endl;
    return 0;
}