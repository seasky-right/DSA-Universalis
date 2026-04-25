#include <iostream>
using namespace std;

struct BTNode {
    int data;
    BTNode* lchild, *rchild;
    BTNode() : lchild(nullptr), rchild(nullptr) {}
    BTNode(int x) : data(x), lchild(nullptr), rchild(nullptr) {}
};

BTNode* CreateTree() {
    int x;
    if(!(cin >> x) || x == -1) return nullptr;

    BTNode* s = new BTNode(x);

    s -> lchild = CreateTree();
    s -> rchild = CreateTree();

    return s;
}

void Mirror(BTNode* r){
    if(!r) return;
    Mirror(r -> lchild);
    Mirror(r -> rchild);

    swap(r -> lchild, r -> rchild);
}

void DispTree(BTNode* r, bool& isFirst){
    if(!r) return;

    if(!isFirst) cout << " ";
    cout << r -> data;
    isFirst = false;

    DispTree(r -> lchild, isFirst);
    DispTree(r -> rchild, isFirst);
}

int main(){
    BTNode* r = CreateTree();
    Mirror(r);

    bool isFirst = true;
    DispTree(r, isFirst);

    cout << endl;
    return 0;
}