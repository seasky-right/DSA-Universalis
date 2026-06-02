#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct node {
    int data;
    node* lchild, *rchild;

    node(int d) : data(d), lchild(nullptr), rchild(nullptr) {}
};

node* CreateTree(istringstream& iss){
    int x;
    if(!(iss >> x) || x == -1) return nullptr;

    node* root = new node(x);
    root -> lchild = CreateTree(iss);
    root -> rchild = CreateTree(iss);

    return root;
}

bool isSame(node*& t1, node*& t2){
    if(!t1 && !t2) return true;
    if(!t1 || !t2) return false;
    if(t1 -> data != t2 -> data) return false;
    return isSame(t1 -> lchild, t2 -> lchild) && isSame(t1 -> rchild, t2 -> rchild);
}

int main(){
    string line1, line2;
    getline(cin, line1);
    getline(cin, line2);
    istringstream iss1(line1), iss2(line2);
    node* root1 = CreateTree(iss1);
    node* root2 = CreateTree(iss2);

    if(isSame(root1, root2)) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}