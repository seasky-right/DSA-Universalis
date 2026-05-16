#include <iostream>
#include <fstream>
using namespace std;

struct BTNode{
    int data;
    BTNode* lchild;
    BTNode* rchild;
    BTNode(int i) : data(i), lchild(nullptr), rchild(nullptr) {}
};

int max_dia = 0;

BTNode* CreateBTree(string& s, int& i){
    if(i >= s.size()) return nullptr;
    if(s[i] == ',' || s[i] == ')') return nullptr;

    int num = 0;
    while(s[i] >= '0' && s[i] <= '9'){
        num = num * 10 + (s[i++] - '0');
    }

    BTNode* p = new BTNode(num);

    if(i < s.size()){
        if(s[i] == '('){
            i++;
            p -> lchild = CreateBTree(s, i);

            if(s[i] == ','){
                i++;
                p -> rchild = CreateBTree(s, i);
            }

            if(s[i] == ')'){
                i++;
            }
        }
    }

    return p;
}

int Diameter(BTNode* r){
    if(!r) return 0;
    int leftHeight = Diameter(r -> lchild);
    int rightHeight = Diameter(r -> rchild);

    max_dia = max(max_dia, leftHeight + rightHeight);
    return max(leftHeight, rightHeight) + 1;
}

int main(){
    ifstream infile("in.txt");
    string str; infile >> str;
    int i = 0;
    BTNode* root = CreateBTree(str, i);

    Diameter(root);

    cout << max_dia << endl;
    return 0;
}