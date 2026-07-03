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

node* head = nullptr;
node* tail = nullptr;
void convert(node* root, node*& pre) {
    if(!root) return;
    convert(root -> lchild, pre);

    if(pre == nullptr) head = root;
    root -> lchild = pre;
    if(pre) pre -> rchild = root;
    tail = root;

    pre = root;
    convert(root -> rchild, pre);
}

int main() {
    string line;
    getline(cin, line);
    istringstream iss(line);

    node* root = CreateTree(iss);

    node* pre = nullptr;
    convert(root, pre);

    cout << head -> data << " " << tail -> data << endl;
    return 0;
}
