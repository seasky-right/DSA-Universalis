#include <iostream>
#include <stack>
#include <queue>
#include <fstream>
using namespace std;

struct BTNode{
    char data;
    BTNode* lchild, *rchild;
    BTNode(char d) : data(d), lchild(nullptr), rchild(nullptr) {}
};

BTNode* CreateBTree(string str){
    stack<BTNode*> st;
    for(char c : str){
        BTNode* p = new BTNode(c);
        if(c >= 'A' && c <= 'Z'){
            BTNode* a = st.top(); st.pop();
            BTNode* b = st.top(); st.pop();
            p -> lchild = b;
            p -> rchild = a;
            st.push(p);
        }else if(c >= 'a' && c <= 'z'){
            st.push(p);
        }
    }
    return st.top();
}

void Display(BTNode* root){
    queue<BTNode*> qu;
    qu.push(root);
    vector<char> res;
    while(!qu.empty()){
        BTNode* curr = qu.front(); qu.pop();
        res.push_back(curr -> data);
        if(curr -> lchild) qu.push(curr -> lchild);
        if(curr -> rchild) qu.push(curr -> rchild);
    }
    for(int i = res.size() - 1; i >= 0; --i){
        cout << res[i];
    }
}

int main(){
    ifstream in("in.txt");
    string str; in >> str;
    BTNode* root = CreateBTree(str);
    Display(root);

    cout << endl;
    return 0;
}