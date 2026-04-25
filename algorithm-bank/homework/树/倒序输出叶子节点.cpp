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

void DispLeaves(BTNode* r, bool& isFirst){
    if(!r) return;

    DispLeaves(r -> rchild, isFirst);

    if(!r -> lchild && !r -> rchild){
        if(!isFirst) cout << " ";
        cout << r -> data;
        isFirst = false;
    }

    DispLeaves(r -> lchild, isFirst);
}

int main(){
    BTNode* r = CreateTree();

    bool isFirst = true;
    DispLeaves(r, isFirst);

    cout << endl;
    return 0;
}