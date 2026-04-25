#include <iostream>
#include <stack>

using namespace std;

struct BTNode {
    char data;
    BTNode* lchild;
    BTNode* rchild;
    BTNode() : lchild(nullptr), rchild(nullptr) {}
    BTNode(char d) : data(d), lchild(nullptr), rchild(nullptr) {}
};

class BTree {
    BTNode* root;
public:
    BTree() : root(nullptr) {}

    ~BTree(){
        destroy(root);
    }
    void destroy(BTNode* p){
        if(p){
            destroy(p -> lchild);
            destroy(p -> rchild);
            delete p;
        }
    }

    void CreateBTree(string str){
        stack<BTNode*> st;
        BTNode* p;
        bool flag = true; //标志位，true表示当前节点的左子树
        int i = 0;

        while(i < str.length()){
            char c = str[i];
            switch(c){
                case '(':
                    st.push(p);
                    flag = true;
                    break;
                case ')':
                    st.pop();
                    break;
                case ',':
                    flag = false;
                    break;
                default:
                    p = new BTNode(c);
                    if(!root) root = p;
                    else{
                        if(flag && !st.empty())
                            st.top() -> lchild = p;
                        else if(!st.empty())
                            st.top() -> rchild = p;
                    }
                    break;
            }
            i++;
        }
    }

    void DispBTree(){
        disp(root);
    }
    void disp(BTNode* p){
        if(p){
            cout << p -> data;
            if(p -> lchild || p -> rchild){
                cout << '(';
                disp(p -> lchild);
                if(p -> rchild) cout << ',';
                disp(p -> rchild);
                cout << ')';
            }
        }
    }

    BTNode* FindNode(char x){
        return findNode(root, x);
    }
    BTNode* findNode(BTNode* p, char x){
        if(!p) return nullptr;
        if(p -> data == x) return p;
        BTNode* res = findNode(p -> lchild, x);
        if(!res) res = findNode(p -> rchild, x);
        return res;
    }

    int Height(){
        return height(root);
    }
    int height(BTNode* p){
        if(!p) return 0;
        int hl = height(p -> lchild);
        int hr = height(p -> rchild);
        return max(hr, hl) + 1;
    }

    void PreOrderRecursion(){
        preOrderr(root);
    }
    void preOrderr(BTNode* p){
        if(p){
            cout << p -> data << " ";
            preOrderr(p -> lchild);
            preOrderr(p -> rchild);
        }
    }

    void InOrderRecursion(){
        inOrderr(root);
    }
    void inOrderr(BTNode* p){
        if(p){
            inOrderr(p -> lchild);
            cout << p -> data << " ";
            inOrderr(p -> rchild);
        }
    }

    void PostOrderRecursion(){
        postOrderr(root);
    }
    void postOrderr(BTNode* p){
        if(p){
            postOrderr(p -> lchild);
            postOrderr(p -> rchild);
            cout << p -> data << " ";
        }
    }

    void PreOrderIteration(){
        if(!root) return;
        stack<BTNode*> st;
        BTNode* p;
        st.push(root);
        
        while(!st.empty()){
            
        }
    }
};
