#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct BTNode{
    char data;
    BTNode* lchild, *rchild;
    BTNode(char d) : data(d), lchild(nullptr), rchild(nullptr) {}
};

int findIndex(const vector<char>& InOrder, int il, int ir, char x){
    for(int i = il; i <= ir; ++i){
        if(InOrder[i] == x) return i;
    }
    return -1;
}
BTNode* CreateBTree(
    const vector<char>& levelOrder,
    const vector<char>& inOrder,
    int inL, int inR
){
    if(levelOrder.empty() || inL > inR) return nullptr;
    BTNode* root = new BTNode(levelOrder[0]);
    if(inL == inR) return root;

    int pos = findIndex(inOrder, inL, inR, levelOrder[0]);
    
    vector<char> leftlevel, rightlevel;
    for(size_t i = 1; i < levelOrder.size(); ++i){
        int idx = findIndex(inOrder, inL, inR, levelOrder[i]);

        if(idx != -1){
            if(idx < pos) leftlevel.push_back(levelOrder[i]);
            else rightlevel.push_back(levelOrder[i]);
        }
    }

    root -> lchild = CreateBTree(leftlevel, inOrder, inL, pos - 1);
    root -> rchild = CreateBTree(rightlevel, inOrder, pos + 1, inR);

    return root;
}

void DispBTree(BTNode* root, bool& f){
    if(!root) return;
    if(!f) cout << " ";
    f = false;
    cout << root -> data;
    if(root -> lchild) DispBTree(root -> lchild, f);
    if(root -> rchild) DispBTree(root -> rchild, f);
}

int main(){
    int n; cin >> n;
    cin.ignore();

    string level; getline(cin, level);
    istringstream le(level);
    vector<char> levelOrder;
    for(int i = 0; i < level.size(); ++i){
        char c; le >> c;
        levelOrder.push_back(c);
    }

    string in; getline(cin, in);
    istringstream inn(in);
    vector<char> inOrder;
    for(int i = 0; i < n; ++i){
        char c; inn >> c;
        inOrder.push_back(c);
    }

    BTNode* root = CreateBTree(levelOrder, inOrder, 0, n - 1);

    bool isFirst = true;
    DispBTree(root, isFirst);
    cout << endl;
    return 0;
}