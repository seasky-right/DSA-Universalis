#include <iostream>
#include <queue>
using namespace std;

struct BTNode{
    char data;
    BTNode* lchild, *rchild;
    BTNode(char d) : data(d), lchild(nullptr), rchild(nullptr) {}
};

BTNode* CreateBTree(string str){
    int i = 0;
    if(str[i] == '#') return nullptr;
    BTNode* s = new BTNode(str[i]);
    i++;
    queue<BTNode*> qu;
    qu.push(s);

    while(!qu.empty()){
        if(qu.front() == nullptr){
            qu.pop();
            i += 2; // 一个空节点在下一层占用2个孩子的字符位置，直接跳过它们
            continue;
        }
        BTNode* curr = qu.front(); qu.pop();

        if(i < str.size() && i < str.size()){
            if(str[i] != '#'){
                BTNode* left = new BTNode(str[i]);
                curr -> lchild = left;
                qu.push(left);
            }else{
                qu.push(nullptr);
            }
        }
        i++;

        if(i < str.size()){
            if(str[i] != '#'){
                BTNode* right = new BTNode(str[i]);
                curr -> rchild = right;
                qu.push(right);
            }else{
                qu.push(nullptr);
            }
        }
        i++;
    }
    
    return s;
}

bool isSingle(BTNode* p){
    if(!p) return false;
    return ((p -> lchild && !p -> rchild) || (p -> rchild && !p -> lchild));
}
int Single(BTNode* root, int& count){
    if(!root) return count;
    if(isSingle(root)) count++;
    if(root -> lchild) Single(root -> lchild, count);
    if(root -> rchild) Single(root -> rchild, count);

    return count;
}

int main(){
    string str; cin >> str;
    BTNode* root = CreateBTree(str);

    int count = 0;
    cout << Single(root, count) << endl;
    return 0;
}