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

int Height(BTNode* r){
    if(!r) return 0;
    return 1 + max(Height(r -> lchild), Height(r -> rchild));
}

int main() {
    BTNode* r = CreateTree();
    
    cout << Height(r) << endl;
    return 0;
}