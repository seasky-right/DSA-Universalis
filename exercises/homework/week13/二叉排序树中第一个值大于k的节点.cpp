#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

struct BSTNode {
    int key;
    BSTNode* lchild, *rchild;

    BSTNode(int val) : key(val), lchild(nullptr), rchild(nullptr) {}
};

BSTNode* CreateBST(BSTNode*& root, const vector<int>& arr) {
    if(arr.empty()) return root;
    queue<BSTNode*> q;
    root = new BSTNode(arr[0]);
    q.push(root);

    int idx = 1;
    while(!q.empty() && idx < arr.size()) {
        BSTNode* node = q.front();
        q.pop();

        if(idx < arr.size()) {
            if(arr[idx] != -1) {
                node -> lchild = new BSTNode(arr[idx++]);
                q.push(node -> lchild);
            }
            else {
                node -> lchild = nullptr;
                idx++;
            }
        }
        if(idx < arr.size()) {
            if(arr[idx] != -1) {
                node -> rchild = new BSTNode(arr[idx++]);
                q.push(node -> rchild);
            }
            else {
                node -> rchild = nullptr;
                idx++;
            }
        }
    }
    return root;
}

int SearchBST(BSTNode* root, int k, int& ans) {
    if(!root) return ans;

    if(root -> key > k) {
        ans = root -> key;
        return SearchBST(root -> lchild, k, ans);
    } else {
        return SearchBST(root -> rchild, k, ans);
    }
}

int main(){
    int n; cin >> n;
    cin.ignore();
    vector<int> arr;

    string line;
    getline(cin, line);
    istringstream iss(line);
    int val;
    while(iss >> val) {
        arr.push_back(val);
    }

    BSTNode* root = nullptr;
    root = CreateBST(root, arr);

    int k; cin >> k;
    int ans = -1;

    cout << SearchBST(root, k, ans) << endl;
    return 0;
}