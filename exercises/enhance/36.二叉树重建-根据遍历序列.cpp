#include <iostream>
#include <vector>
using namespace std;

struct node {
    int data;
    node* lchild, *rchild;

    node(int d) : data(d), lchild(nullptr), rchild(nullptr) {}
};

node* CreateTree(
    const vector<int>& pre, 
    const vector<int>& in, 
    int& i, int inL, int inR) {
    if(i >= pre.size() || inL > inR) return nullptr;

    int d = pre[i++];
    node* root = new node(d);

    int pos = inL;
    while(in[pos] != d) pos++;

    root -> lchild = CreateTree(pre, in, i, inL, pos - 1);
    root -> rchild = CreateTree(pre, in, i, pos + 1, inR);

    return root;
}

void postOrder(node* root, bool& f) {
    if(!root) return;

    postOrder(root -> lchild, f);
    postOrder(root -> rchild, f);

    if(!f) cout << " ";
    cout << root -> data;
    f = false;
}

int main() {
    int n; cin >> n;
    vector<int> preorder(n), inorder(n);

    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        preorder[i] = x;
    }
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        inorder[i] = x;
    }

    int i = 0, inL = 0, inR = n - 1;
    node* root = CreateTree(preorder, inorder, i, inL, inR);

    bool isFirst = true;
    postOrder(root, isFirst);

    cout << endl;
    return 0;
}