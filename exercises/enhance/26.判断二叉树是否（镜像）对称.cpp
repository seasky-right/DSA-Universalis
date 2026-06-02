#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct BTNode {
    int data;
    BTNode* lchild, *rchild;

    BTNode(int d) : data(d), lchild(nullptr), rchild(nullptr) {}
};

BTNode* CreateTree(istringstream& iss) {
    int x;
    if(!(iss >> x) || x == -1) return nullptr;

    BTNode* root = new BTNode(x);
    root -> lchild = CreateTree(iss);
    root -> rchild = CreateTree(iss);

    return root;
}

// 双指针指向左右子树
bool _IsMirror(BTNode* p, BTNode* q) {
    if(!p && !q) return true;
    if(!p || !q) return false;
    if(p -> data != q -> data) return false;
    return _IsMirror(p -> lchild, q -> rchild) && _IsMirror(p -> rchild, q -> lchild);
}
bool IsMirror(BTNode* root) {
    if(!root) return true;
    return _IsMirror(root -> lchild, root -> rchild);
}

int main() {
    string line;
    getline(cin, line);
    istringstream iss(line);
    BTNode* root = CreateTree(iss);
    if(IsMirror(root)) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}