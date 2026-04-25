#include <iostream>
#include <vector>
using namespace std;

struct BTNode {
    int data;
    BTNode* lchild, *rchild;
    BTNode() : lchild(nullptr), rchild(nullptr) {}
    BTNode(int x) : data(x), lchild(nullptr), rchild(nullptr) {}
};

BTNode* CreateTree() {
    int x;
    if(!(cin >> x) || x == -1) return nullptr;

    BTNode* s = new BTNode(x);
    s -> lchild = CreateTree();
    s -> rchild = CreateTree();

    return s;
}

void PostDisp(BTNode* r, bool& f){
    if(!r) return;

    PostDisp(r -> lchild, f);
    PostDisp(r -> rchild, f);

    if(!f) cout << " ";
    cout << r -> data;
    f = false;
}

void InDisp(BTNode* r, bool& f){
    if(!r) return;

    InDisp(r -> lchild, f);

    if(!f) cout << " ";
    cout << r -> data;
    f = false;

    InDisp(r -> rchild, f);
}

void dfs(BTNode* r, int level, vector<vector<int>>& res){
    if(!r) return;

    if(level == res.size()) res.push_back(vector<int>());

    res[level].push_back(r -> data);

    dfs(r -> lchild, level + 1, res);
    dfs(r -> rchild, level + 1, res);
}
void LevelDisp(BTNode* r){
    vector<vector<int>> res;
    dfs(r, 0, res);

    bool isFirst = true;
    for(int i = 0; i < res.size(); ++i){
        for(int j = 0; j < res[i].size(); ++j){
            if(!isFirst) cout << " ";
            cout << res[i][j];
            isFirst = false;
        }
    }
}

int main(){
    BTNode* r = CreateTree();

    bool flag = true;
    InDisp(r, flag);
    cout << endl;

    flag = true;
    PostDisp(r, flag);
    cout << endl;

    LevelDisp(r);
    cout << endl;

    return 0;
}