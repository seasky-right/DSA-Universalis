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

node* FindLCA(node* root, int p, int q) {
    if(!root) return nullptr;

    if(root -> data > p && root -> data > q) 
        return FindLCA(root -> lchild, p, q);

    if(root -> data < p && root -> data < q) 
        return FindLCA(root -> rchild, p, q);

    return root;
}

int main() {
    int p, q; cin >> p >> q;
    cin.ignore();
    string line;
    getline(cin, line);
    istringstream iss(line);

    node* root = CreateTree(iss);

    node* s = FindLCA(root, p, q);

    cout << s -> data << endl;
    return 0;
}

