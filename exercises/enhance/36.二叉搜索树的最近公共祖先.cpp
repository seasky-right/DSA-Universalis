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

