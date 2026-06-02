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

void serialize(node* root, bool& f) {
    if(!f) cout << ",";
    f = false;

    if(!root) {
        cout << "#";
        return;
    }

    cout << root -> data;
    serialize(root -> lchild, f);
    serialize(root -> rchild, f);
}

void inOrder(node* root, bool& f) {
    if(!root) return;

    inOrder(root -> lchild, f);

    if(!f) cout << " ";
    cout << root -> data;
    f = false;

    inOrder(root -> rchild, f);
}

int main() {
    string line;
    getline(cin, line);
    istringstream iss(line);

    node* root = CreateTree(iss);

    bool isFirst = true;
    serialize(root, isFirst);
    cout << endl;

    isFirst = true;
    inOrder(root, isFirst);
    cout << endl;

    return 0;
}