#include <iostream>
using namespace std;

struct BTNode {
    char data;
    BTNode* lchild, *rchild;
    BTNode() : lchild(nullptr), rchild(nullptr) {}
    BTNode(char x) : data(x), lchild(nullptr), rchild(nullptr) {}
};

BTNode* CreateTree(const string& str, int& i){
    if(i >= str.length()) return nullptr;
    

}