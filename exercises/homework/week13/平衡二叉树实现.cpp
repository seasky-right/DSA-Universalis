#include <iostream>
#include <vector>
using namespace std;

struct Node {
    char data;
    int height;
    Node* lchild, *rchild;

    Node(char d) : data(d), height(1), lchild(nullptr), rchild(nullptr) {}
};

int getHeight(Node* p) { return p ? p -> height : 0; }

int getBF(Node* p) { return p ? 
    getHeight(p -> lchild) - getHeight(p -> rchild) : 0;}

void rightRotate(Node*& p) {
    Node* left = p -> lchild;
    p -> lchild = left -> rchild;
    left -> rchild = p;
    
    p -> height = 1 + max(getHeight(p -> lchild), getHeight(p -> rchild));
    left -> height = 1 + max(getHeight(left -> lchild), getHeight(left -> rchild));
    p = left;
}

void leftRotate(Node*& p) {
    Node* right = p -> rchild;
    p -> rchild = right -> lchild;
    right -> lchild = p;

    p -> height = 1 + max(getHeight(p -> lchild), getHeight(p -> rchild));
    right -> height = 1 + max(getHeight(right -> lchild), getHeight(right -> rchild));
    p = right;
}

void balance(Node*& p) {
    if(!p) return;
    p -> height = 1 + max(getHeight(p -> lchild), getHeight(p -> rchild));

    int bf = getBF(p);

    if(bf > 1) {
        if(getBF(p -> lchild) >= 0) {
            rightRotate(p);
        } else {
            leftRotate(p -> lchild);
            rightRotate(p);
        }
    }

    else if(bf < -1) {
        if(getBF(p -> rchild) <= 0) {
            leftRotate(p);
        } else {
            rightRotate(p -> rchild);
            leftRotate(p);
        }
    }
}

void insert(Node*& p, char data) {
    if(!p) {
        p = new Node(data);
        return;
    }

    if(data < p -> data) insert(p -> lchild, data);
    else if(data > p -> data) insert(p -> rchild, data);
    else return; // 已存在，不插入

    balance(p);
}

void remove(Node*& p, char data) {
    if(!p) return;

    if(data < p -> data) remove(p -> lchild, data);
    else if(data > p -> data) remove(p -> rchild, data);
    else {
        if(!p -> lchild || !p -> rchild) {
            Node* temp = p -> lchild ? p -> lchild : p -> rchild;
            delete p;
            p = temp;
        } else {
            Node* successor = p -> rchild;
            while(successor -> lchild) successor = successor -> lchild;
            p -> data = successor -> data; // 替换数据
            remove(p -> rchild, successor -> data); // 删除后继节点
        }
    }
    balance(p);
}

void postOrder(Node* p) {
    if(!p) return;
    postOrder(p -> lchild);
    postOrder(p -> rchild);
    cout << p -> data;
}

int main() {
    Node* root = nullptr;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        char c; cin >> c;
        insert(root, c);
    }

    int m; cin >> m;
    for(int i = 0; i < m; i++) {
        char c; cin >> c;
        remove(root, c);
    }

    postOrder(root);
    cout << endl;

    return 0;
}