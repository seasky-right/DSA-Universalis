#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct node {
    char data;
    node* lchild, *rchild;

    node(char c) : data(c), lchild(nullptr), rchild(nullptr) {}
};

node* CreateTree(const string& str) {
    stack<node*> st;
    node* p = nullptr, *root = nullptr;
    int i = 0;
    bool flag = true;

    while(i < str.size()) {
        switch(str[i]) {
            case '(' :
                st.push(p);
                flag = true;
                break;
            case ',' :
                flag = false;
                break;
            case ')' :
                st.pop();
                break;
            default :
                p = new node(str[i]);
                if(!root) root = p;
                else if(!st.empty()) {
                    if(flag) st.top() -> lchild = p;
                    else st.top() -> rchild = p;
                }
        }
        i++;
    }

    return root;
}

node* CreateTree(const string& str, int& i) {
    if(i >= str.size()) return nullptr;
    if(str[i] == ',' || str[i] == ')') return nullptr;

    node* s = new node(str[i]);
    i++;

    if(str[i] == '(') {
        i++;
        s -> lchild = CreateTree(str, i);
        if(str[i] == ',') {
            i++;
            s -> rchild = CreateTree(str, i);
        }

        if(str[i] == ')') i++;
    }

    return s;
}

void postOrder(node* root, bool& f) {
    if(!root) return;
    
    postOrder(root -> lchild, f);
    postOrder(root -> rchild, f);

    if(!f) cout << " ";
    cout << root -> data;
    f = false;
}

int main() {
    string line;
    getline(cin, line);

    node* root = CreateTree(line);

    bool isFirst = true;
    postOrder(root, isFirst);
    
    cout << endl;
    return 0;
}