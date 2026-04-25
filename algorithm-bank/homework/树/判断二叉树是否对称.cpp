#include <iostream>
using namespace std;

struct BTNode {
    char data;
    BTNode* lchild, *rchild;
    BTNode() : lchild(nullptr), rchild(nullptr) {}
    BTNode(char x) : data(x), lchild(nullptr), rchild(nullptr) {}
};

BTNode* CreateTree() {
    char x;
    if(!(cin >> x) || x == '#') return nullptr;

    BTNode* s = new BTNode(x);
    s -> lchild = CreateTree();
    s -> rchild = CreateTree();

    return s;
}

bool IsSymmetric(BTNode* r){
    if(!r) return true;
    if(!r -> lchild && !r -> rchild) return true;
    if(!r -> lchild || !r -> rchild) return false;
    if(r -> lchild -> data != r -> rchild -> data) return false;
    return IsSymmetric(r -> lchild) && IsSymmetric(r -> rchild);
}

int main(){
    BTNode* r = CreateTree();
    if(IsSymmetric(r)) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}