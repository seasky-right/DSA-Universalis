#include <iostream>

using namespace std;

struct BTNode{
    char data;
    BTNode* lchild, *rchild;
    BTNode(char d) : data(d), lchild(nullptr), rchild(nullptr) {}
};

BTNode* CreateBTree(string str, int& i){
    if(i >= str.size()) return nullptr;
    if(str[i] == ',' || str[i] == ')') return nullptr;

    BTNode* s = new BTNode(str[i]);
    i++;

    if(i < str.size()){
        if(str[i] == '('){
            i++;
            s -> lchild = CreateBTree(str, i);
            if(str[i] == ','){
                i++;
                s -> rchild = CreateBTree(str, i);
            }
            if(str[i] == ')'){
                i++;
            }
        }
    }
    return s;
}

void DispLeaves(BTNode* root, bool& f){
    if(!root) return;
    if(!root -> lchild && !root -> rchild){
        if(!f) cout << " ";
        cout << root -> data;
        f = false;
    }
    if(root -> rchild) DispLeaves(root -> rchild, f);
    if(root -> lchild) DispLeaves(root -> lchild, f);
}

int main(){
    string s; cin >> s;
    int i = 0;
    BTNode* root = CreateBTree(s, i);

    bool isFirst = true;
    DispLeaves(root, isFirst);

    cout << endl;
    return 0;
}