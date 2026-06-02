#include <iostream>
#include <string>
#include <sstream>
#include <queue>
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

void inOrder(node* root, bool& f) {
    if(!root) return;

    inOrder(root -> lchild, f);

    if(!f) cout << " ";
    cout << root -> data;
    f = false;

    inOrder(root -> rchild, f);
}

void postOrder(node* root, bool& f) {
    if(!root) return;

    postOrder(root -> lchild, f);
    postOrder(root -> rchild, f);

    if(!f) cout << " ";
    cout << root -> data;
    f = false;
}

void levelOrder(node* root) {
    if(!root) return;
    queue<node*> qu;
    qu.push(root);

    bool isFirst = true;
    while(!qu.empty()) {
        node* p = qu.front(); qu.pop();
        if(!isFirst) cout << " ";
        cout << p -> data;
        isFirst = false;

        if(p -> lchild) qu.push(p -> lchild);
        if(p -> rchild) qu.push(p -> rchild);
    }
}

int main() {
    string line;
    getline(cin, line);
    istringstream iss(line);
    node* root = CreateTree(iss);

    bool isFirst = true;
    inOrder(root, isFirst);
    cout << endl;

    isFirst = true;
    postOrder(root, isFirst);
    cout << endl;

    levelOrder(root);
    cout << endl;

    return 0;
}