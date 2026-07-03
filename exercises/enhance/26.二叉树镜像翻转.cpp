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

void Mirror(node* root) {
    if(!root) return;
    swap(root -> lchild, root -> rchild);
    Mirror(root -> lchild);
    Mirror(root -> rchild);
}

void preOrder(node* root, bool& f){
    if(!root) return;
    if(!f) cout << " ";
    cout << root -> data;
    f = false;
    preOrder(root -> lchild, f);
    preOrder(root -> rchild, f);
}

int main() {
    string line;
    getline(cin, line);
    istringstream iss(line);
    node* root = CreateTree(iss);
    
    Mirror(root);
    bool isFirst = true;
    preOrder(root, isFirst);

    cout << endl;
    return 0;
}