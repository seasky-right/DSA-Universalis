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

void CopyTree(BTNode* r, BTNode*& newR){
    if(!r) return;

    newR = new BTNode(r -> data);
    CopyTree(r -> lchild, newR -> lchild);
    CopyTree(r -> rchild, newR -> rchild);
}

void InDisp(BTNode* r, bool& f){
    if(!r) return;

    InDisp(r -> lchild, f);

    if(!f) cout << " ";
    cout << r -> data;
    f = false;

    InDisp(r -> rchild, f);
}

int main(){
    BTNode* r = CreateTree();
    BTNode* newR = nullptr;
    CopyTree(r, newR);

    bool isFirst = true;
    InDisp(newR, isFirst);

    cout << endl;
    return 0;
}