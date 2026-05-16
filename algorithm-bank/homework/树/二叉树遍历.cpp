#include <iostream>
#include <string>
using namespace std;

struct BTNode {
    char data;
    BTNode* lchild, *rchild;
    BTNode() : lchild(nullptr), rchild(nullptr) {}
    BTNode(char x) : data(x), lchild(nullptr), rchild(nullptr) {}
};

BTNode* CreateTree(const string& str, int& i){
    if(i >= str.length()) return nullptr;
    if(str[i] == ',' || str[i] == ')') return nullptr;

    BTNode* s = new BTNode(str[i]);
    i++;

    if(i < str.length()){
        if(str[i] == '('){
            i++;

            s -> lchild = CreateTree(str, i);
            if(str[i] == ','){
                i++;
                s -> rchild = CreateTree(str, i);
            }

            if(str[i] == ')'){
                i++;
            }
        }
    }
    
    return s;
}

void prepre(BTNode* p){
    if(p){
        cout << p -> data;

        prepre(p -> lchild);
        prepre(p -> rchild);
    }
    
}
void PreDisp(BTNode* hh){
    prepre(hh);
    cout << endl;
}

void inin(BTNode* p){
    if(p){
        inin(p -> lchild);

        cout << p -> data;

        inin(p -> rchild);
    }
}
void InDisp(BTNode* hh){
    inin(hh);
    cout << endl;
}

void postpost(BTNode* p){
    if(p){
        postpost(p -> lchild);
        postpost(p -> rchild);

        cout << p -> data;
    }
}
void PostDisp(BTNode* hh){
    postpost(hh);
    cout << endl;
}

int main(){
    string line;
    getline(cin, line);

    int index = 0;
    BTNode* p = CreateTree(line, index);

    PreDisp(p);
    InDisp(p);
    PostDisp(p);

    return 0;
}