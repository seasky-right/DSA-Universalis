#include <iostream>
#include <vector>
using namespace std;

struct BTNode {
    char data;
    BTNode* lchild, *rchild;

    BTNode(char d) : data(d), lchild(nullptr), rchild(nullptr) {}
};

BTNode* nodes[1005] = {nullptr};
vector<int> charToLines[256];
bool hasParent[1005] = {false};

char leftChar[1005];
char rightChar[1005];

void preOrder(BTNode* root, int height) {
    if(!root) return;
    cout << root -> data << " " << height << endl;
    preOrder(root -> lchild, height + 1);
    preOrder(root -> rchild, height + 1);
}

int main() {
    int n; cin >> n;
    for(int i = 0; i < n; ++i) {
        char p, l, r;
        cin >> p >> l >> r;
        
        nodes[i] = new BTNode(p);

        charToLines[p].push_back(i);

        leftChar[i] = l;
        rightChar[i] = r;
    }

    for(int i = 1; i <= n; ++i) {
        char l = leftChar[i];
        if(l != '#') {
            for(int idx : charToLines[l]) {
                nodes[i] -> lchild = nodes[idx];
                hasParent[idx] = true;
                break;
            }
        }

        char r = rightChar[i];
        if (r != '#') {
            for (int idx : charToLines[r]) {
                if (!hasParent[idx]) {
                    nodes[i]->rchild = nodes[idx];
                    hasParent[idx] = true;
                    break;
                }
            }
        }
    }

    BTNode* root = nullptr;
    for(int i = 0; i < n; ++i) {
        if (!hasParent[i]) {
            root = nodes[i];
            break;
        }
    }

    preOrder(root, 1);
    return 0;
}