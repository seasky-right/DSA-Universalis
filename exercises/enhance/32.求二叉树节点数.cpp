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

int countNodes(node* root) {
    if(!root) return 0;
    return 1 + countNodes(root -> lchild) + countNodes(root -> rchild);
}

int main() {
    string line;
    getline(cin, line);
    istringstream iss(line);
    node* root = CreateTree(iss);

    cout << countNodes(root) << endl;
    return 0;
}