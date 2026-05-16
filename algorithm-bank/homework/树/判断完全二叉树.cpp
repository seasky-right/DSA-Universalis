#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
using namespace std;

struct BTNode{
    int data;
    BTNode* lchild;
    BTNode* rchild;
    BTNode(int i) : data(i), lchild(nullptr), rchild(nullptr) {}
};

BTNode* CreateBTree(string s){
    stack<BTNode*> st;
    BTNode* p = nullptr, *root = nullptr;
    bool flag = true;
    int i = 0;

    while(i < s.size()){
        switch(s[i]){
            case '(':
                st.push(p);
                flag = true;
                break;
            case ')':
                st.pop();
                break;
            case ',':
                flag = false;
                break;
            default:
                int num = 0;
                while(s[i] >= '0' && s[i] <= '9'){
                    num = num * 10 + s[i++];
                } 
                i--;
                p = new BTNode(num);
                if(st.empty()) root = p;
                else{
                    if(flag) st.top() -> lchild = p;
                    else st.top() -> rchild = p;
                }
                break;
        }
        i++;
    }
    return root;
}

bool Order(BTNode* r){
    if(!r) return true;

    queue<BTNode*> tree;
    BTNode* p;
    tree.push(r);

    bool hasMetNull = false;

    while(!tree.empty()){
        p = tree.front(); tree.pop();
        if(!p) hasMetNull = true;
        else{
            if(hasMetNull) return false;
            tree.push(p -> lchild);
            tree.push(p -> rchild);
        }
    }
    return true;
}

int main(){
    ifstream infile("in.txt");
    string str; infile >> str;
    BTNode* root = CreateBTree(str);

    if(Order(root)) cout << 1 << endl;
    else cout << 0 << endl;

    return 0;
}
