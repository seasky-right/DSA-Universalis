#include <iostream>
#include <string>
using namespace std;

struct node {
    char data;
    node* lchild, *rchild;

    node(char d) : data(d), lchild(nullptr), rchild(nullptr) {}
};

node* CreateBTree(const string& str, int& i) {
    if(i >= str.size()) return nullptr;
    if(str[i] == ',' || str[i] == ')') return nullptr;

    node* s = new node(str[i]);
    i++;

    if(i < str.size() && str[i] == '(') {
        i++;
        s->lchild = CreateBTree(str, i);
        if(str[i] == ',') {
            i++;
            s->rchild = CreateBTree(str, i);
        }
        if(str[i] == ')') i++;
    }
    return s;
}

bool isBranch(node* p) {
    return p -> lchild || p -> rchild;
}

void preOrder(node* root) {
    if(!root) return;
    if(isBranch(root)) cout << root -> data;
    preOrder(root -> lchild);
    preOrder(root -> rchild);
}

int main() {
    string line;
    getline(cin, line);

    if(line.empty()) {
        cout << endl;
        return 0;
    }

    int i = 0;
    node* root = CreateBTree(line, i);

    preOrder(root);
    cout << endl;

    return 0;
}