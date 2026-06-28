#include <iostream>
using namespace std;

struct node {
    int data;
    node* lchild, *rchild;

    node(int d) : data(d), lchild(nullptr), rchild(nullptr) {}
};

node* Insert(node* root, int x) {
    if(!root) return new node(x);

    if(root -> data > x) root -> lchild = Insert(root -> lchild, x);
    else if(root -> data < x) root -> rchild = Insert(root -> rchild, x);

    return root;
}

node* Find(node* root, int x) {
    if(!root) return nullptr;
    if(root -> data > x) return Find(root -> lchild, x);
    else if(root -> data < x) return Find(root -> rchild, x);

    return root;
}

node* Delete(node* root, int x);