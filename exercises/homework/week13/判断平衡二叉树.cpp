#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

struct AVLNode {
    int data;
    int height;
    AVLNode* lchild, *rchild;

    AVLNode(int d) : data(d), height(1), lchild(nullptr), rchild(nullptr) {}
};

AVLNode* CreateBTree(const vector<int>& arr) {
    if(arr.empty() || arr[0] == -1) return nullptr;
    queue<AVLNode*> qu;
    AVLNode* root = new AVLNode(arr[0]);
    qu.push(root);

    int idx = 1;
    while(!qu.empty() && idx < arr.size()) {
        AVLNode* n = qu.front(); qu.pop();

        if(idx < arr.size()) {
            if(arr[idx] != -1) {
                n -> lchild = new AVLNode(arr[idx]);
                qu.push(n -> lchild);
            }
            idx++;
        }

        if(idx < arr.size()) {
            if(arr[idx] != -1) {
                n -> rchild = new AVLNode(arr[idx]);
                qu.push(n -> rchild);
            }
            idx++;
        }
    }

    return root;
}

bool CheckBalance(AVLNode* root, int& height) {
    if(!root) {
        height = 0;
        return true;
    }

    int lh = 0, rh = 0;
    if(!CheckBalance(root -> lchild, lh)) return false;
    if(!CheckBalance(root -> rchild, rh)) return false;

    height = max(lh, rh) + 1;
    root -> height = height;

    return abs(lh - rh) <= 1;
}

int main() {
    ifstream fin("in.txt");
    string line;
    vector<int> arr;
    while(getline(fin, line)) {
        stringstream iss(line);
        string num;
        while(iss >> num) {
            if(num == "null") num = "-1";
            arr.push_back(stoi(num));
        }
    }

    AVLNode* root = CreateBTree(arr);

    int height = 0;
    ofstream fout("out.txt");
    if(CheckBalance(root, height)) {
        fout << "True" << endl;
    } else {
        fout << "False" << endl;
    }

    return 0;
}
