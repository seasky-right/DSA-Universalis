#include <iostream>
using namespace std;

struct BTNode{
    char lchild;
    char rchild;
    BTNode() : lchild('#'), rchild('#') {}
    BTNode(char l, char r) : lchild(l), rchild(r) {}
};
BTNode tree[256];

void PreOrder(char curr, bool& f){
    if(curr == '#') return;
    if(!f) cout << " ";
    cout << curr;
    f = false;
    PreOrder(tree[curr].lchild, f);
    PreOrder(tree[curr].rchild, f);
}

int main(){
    int n; cin >> n;
    while(n--){
        char c, l, r;
        cin >> c >> l >> r;
        tree[c] = BTNode(l, r);
    }
    char curr; cin >> curr;
    bool isFirst = true;
    PreOrder(tree[curr].lchild, isFirst);
    PreOrder(tree[curr].rchild, isFirst);

    cout << endl;
    return 0;
}