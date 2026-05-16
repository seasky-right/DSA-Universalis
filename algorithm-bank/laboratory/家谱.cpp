#include <iostream>
using namespace std;

struct BTNode{
    char data;
    BTNode *lchild, *rchild;
    BTNode(char d) : data(d), lchild(nullptr), rchild(nullptr) {}
};

BTNode* CreateBTree(string str, int& i) {
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

int GetDepth(BTNode* root, char c){
    if(!root) return -1;
    if(root -> data == c) return 0;

    int left_res = -1, right_res = -1;
    if(root -> lchild){
        left_res = GetDepth(root -> lchild, c);
        if(left_res != -1) return 1 + left_res;
    }

    if(root -> rchild) {
        right_res = GetDepth(root -> rchild, c);
        if(right_res != -1) return 1 + right_res;
    }

    return -1;
}
bool isSameGen(BTNode* root, char a, char b){
    if(!root) return false;
    if(root -> data == a || root -> data == b) return false;
    if(GetDepth(root, a) == GetDepth(root, b)) return true;
    else return false;
}

BTNode* GetNode(BTNode* root, char c){
    if(!root) return nullptr;
    if(root -> data == c) return root;
    if(root -> lchild) return GetNode(root -> lchild, c);
    if(root -> rchild) return GetNode(root -> rchild, c);
}

void PrintChild(BTNode* n){
    if(!n) return;
    if(!n -> lchild && !n -> rchild) cout << n -> data;
    if(n -> lchild) PrintChild(n -> lchild);
    if(n -> rchild) PrintChild(n -> rchild);
}
void GetChild(BTNode* r){
    if(!r) return;
    if(!r -> lchild && !r -> rchild) return;
    cout << "[";
    if(r -> lchild) PrintChild(r -> lchild);
    if(r -> rchild) PrintChild(r -> rchild);
    cout << "]";
}

int main(){
    string str; cin >> str;
    int i = 0;
    BTNode* root = CreateBTree(str, i);

    char a, b; cin >> a >> b;
    if(isSameGen(root, a, b)) cout << "True" << endl;
    else cout << "False" << endl;

    GetChild(GetNode(root, a));
    GetChild(GetNode(root, b));

    return 0;
}