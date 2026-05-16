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

BTNode* parent[100005] = {nullptr};
bool visited[100005] = {false};

vector<int> parseInput(string s){
    vector<int> res;

    for(int i = 0; i < s.size(); ++i){
        int num = 0;
        if(s[i] == '[' || s[i] == ']' || s[i] == ' ') continue;

        if(s[i] == ','){

        }else{
            if(s[i] == '#') res.push_back(-1);
            else{
                while(s[i] >= '0' && s[i] <= '9'){
                    num = num * 10 + (s[i++] - '0');
                }
                res.push_back(num);
                i--;
            }
        }
    }

    return res;
}

BTNode* CreateBTree(vector<int>& res){
    if(res.empty()) return nullptr;

    queue<BTNode*> qu;
    BTNode* p = new BTNode(res[0]);
    qu.push(p);

    int i = 1;

    while(!qu.empty() && i < res.size()){
        BTNode* curr = qu.front();
        qu.pop();

        if(i < res.size() && res[i] != -1){
            curr -> lchild = new BTNode(res[i]);
            parent[res[i]] = curr;
            qu.push(curr -> lchild);
        }
        i++;

        if(i < res.size() && res[i] != -1){
            curr -> rchild = new BTNode(res[i]);
            parent[res[i]] = curr;
            qu.push(curr -> rchild);
        }
        i++;
    }

    return p;
}

BTNode* findTarget(BTNode* root, int target){
    if(!root) return nullptr;
    if(root -> data == target) return root;

    BTNode* leftResult = findTarget(root -> lchild, target);
    if(leftResult) return leftResult;

    return findTarget(root -> rchild, target);
}

void bfs(BTNode* target, int k){
    if(!target) return;
    queue<BTNode*> qu;
    qu.push(target);
    visited[target -> data] = true;
    int dist = 0;

    while(!qu.empty()){
        if(dist == k) break;

        int level_size = qu.size();
        for(int i = 0; i < level_size; ++i){
            BTNode* temp = qu.front(); qu.pop();
            if(temp -> lchild && !visited[temp -> lchild -> data]){
                qu.push(temp -> lchild);
                visited[temp -> lchild -> data] = true;
            }
            if(temp -> rchild && !visited[temp -> rchild -> data]){
                qu.push(temp -> rchild);
                visited[temp -> rchild -> data] = true;
            }
            if(parent[temp -> data] && !visited[parent[temp -> data] -> data]){
                qu.push(parent[temp -> data]);
                visited[parent[temp -> data] -> data] = true;
            }
        }
        dist++;
    }

    cout << "[";
    bool isFirst = true;
    while(!qu.empty()){
        if(!isFirst) cout << ",";
        cout << qu.front() -> data;
        qu.pop();
        isFirst = false;
    }
    cout << "]" << endl;
}

int main(){
    ifstream infile("in.txt");
    string str; infile >> str;
    int target, k; infile >> target >> k;

    vector<int> res = parseInput(str);
    BTNode* root = CreateBTree(res);

    BTNode* targetNode = findTarget(root, target);
    bfs(targetNode, k);
    return 0;
}