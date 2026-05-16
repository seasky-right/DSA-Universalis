#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

struct BTNode{
    int data;
    BTNode* lchild;
    BTNode* rchild;
    BTNode() : lchild(nullptr), rchild(nullptr) {}
    BTNode(int d) : data(d), lchild(nullptr), rchild(nullptr) {}
};

BTNode* CreateBTree(string s, int& i){
    if(i >= s.size()) return nullptr;
    if(s[i] == ')' || s[i] == ',') return nullptr;

    int num = 0;
    while(s[i] >= '0' && s[i] <= '9'){
        num = num * 10 + (s[i++] - '0');
    }

    BTNode* p = new BTNode(num);
    
    if(s[i] == '('){
        i++;
        p -> lchild = CreateBTree(s, i);
        if(s[i] == ','){
            i++;
            p -> rchild = CreateBTree(s, i);
        }
        if(s[i] == ')') i++;
    }

    return p;
}

void dfs(BTNode* root, int depth, vector<int>& res){
    if(!root) return;
    if(depth == res.size()){
        res.push_back(root -> data);
    }

    dfs(root -> rchild, depth + 1, res);
    dfs(root -> lchild, depth + 1, res);
}

void bfs(BTNode* root, vector<int>& res){
    if(!root) return;
    queue<BTNode*> qu;
    qu.push(root);

    while(!qu.empty()){
        int levelSize = qu.size();

        for(int i = 0; i < levelSize; i++){
            BTNode* p = qu.front(); qu.pop();

            if(i == levelSize - 1){
                res.push_back(p -> data);
            }

            if(p -> lchild) qu.push(p -> lchild);
            if(p -> rchild) qu.push(p -> rchild);
        }
    }
}

int main(){
    ifstream infile("in.txt");
    string str; infile >> str;

    int i = 0;
    BTNode* r = CreateBTree(str, i);

    int depth = 0; vector<int> res;
    dfs(r, depth, res);

    cout << "[";
    bool isFirst = true;
    for(size_t i = 0; i < res.size(); ++i){
        if(!isFirst) cout << ",";
        cout << res[i];
        isFirst = false;
    }
    cout << "]" << endl;

    return 0;
}