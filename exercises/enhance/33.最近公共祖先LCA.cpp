// 利用左右支返回值实现父亲的标定
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct node {
    int data;
    node* lchild, *rchild;

    node(int d) : data(d), lchild(nullptr), rchild(nullptr) {}
};

node* CreateTree(istringstream& iss) {
    int x;
    if(!(iss >> x) || x == -1) return nullptr;

    node* root = new node(x);
    root -> lchild = CreateTree(iss);
    root -> rchild = CreateTree(iss);

    return root;
}

node* findNode(node* root, int value) {
    if(!root) return nullptr;
    if(root -> data == value) return root;

    node* leftResult = findNode(root -> lchild, value);
    if(leftResult) return leftResult;

    return findNode(root -> rchild, value);
}

node* findLCA(node* root, node* p, node* q) {
    if(!root) return nullptr;
    if(!p || !q) return nullptr;
    if(root == p || root == q) return root;

    node* leftResult = findLCA(root -> lchild, p, q);
    node* rightResult = findLCA(root -> rchild, p, q);

    if(leftResult && rightResult) return root;

    if(leftResult) return leftResult;
    if(rightResult) return rightResult;

    return nullptr;
}

int main() {
    int p, q; cin >> p >> q;
    cin.ignore();

    string line;
    getline(cin, line);
    istringstream iss(line);
    node* root = CreateTree(iss);

    node* pNode = findNode(root, p);
    node* qNode = findNode(root, q);
    node* lca = findLCA(root, pNode, qNode);

    if(lca) cout << lca -> data << endl;
    else cout << -1 << endl;

    return 0;
}