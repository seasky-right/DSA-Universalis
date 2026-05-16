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
public:
    BTNode* root;

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

    void PreOrderIteration1(){
        if(!root) return;
        stack<BTNode*> st;
        BTNode* p;
        st.push(root);
        
        while(!st.empty()){
            p = st.top(); st.pop();
            cout << p -> data;
            if(p -> rchild) st.push(p -> rchild);
            if(p -> lchild) st.push(p -> lchild);
        }
    }

    struct SNode{
        BTNode* p;
        bool flag;
        SNode() {}
        SNode(BTNode* p1, bool flag1) : p(p1), flag(flag1) {}
    };
    void Push(stack<SNode> &st, BTNode* p){
        if(!(p -> lchild) && !(p -> rchild)) st.push(SNode(p, true));
        else st.push(SNode(p, false));
    }
    void InOrderIteration1(){
        if(!root) return;
        stack<SNode> st;
        BTNode* p = root;
        Push(st, p);

        while(!st.empty()){
            SNode e = st.top(); st.pop();
            p = e.p;
            if(e.flag) cout << p -> data;
            else{
                if(p -> rchild) Push(st, p -> rchild);
                st.push(SNode(p, true));
                if(p -> lchild) Push(st, p -> lchild);
            }
        }
    }

    void PostOrderIteration1(){
        if(!root) return;
        BTNode* p;
        stack<BTNode*> st;
        stack<int> res;
        st.push(root);

        while(!st.empty()){
            p = st.top(); st.pop();
            res.push(p -> data);
            if(p -> lchild) st.push(p -> lchild);
            if(p -> rchild) st.push(p -> rchild);
        }

        while(!res.empty()){
            cout << res.top();
            res.pop();
        }
    }

    void PostOrderTraversal(){
        if(!root) return;
        stack<BTNode*> st;
        BTNode* p = root;

        while(!st.empty() || p){
            while(p){
                cout << p -> data;
                st.push(p);
                p = p -> lchild;
            }
            if(!st.empty()){
                p = st.top(); st.pop();
                p = p -> rchild;
            }
        }
    }

    void InOrderTraversal(){
        if(!root) return;
        stack<BTNode*> st;
        BTNode* p = root;

        while(!st.empty() || p){
            while(p){
                st.push(p);
                p = p -> lchild;
            }
            if(!st.empty()){
                p = st.top(); st.pop();
                cout << p -> data;
                p = p -> rchild;
            }
        }
    }

    void PostOrderTraversal(){
        stack<BTNode*> st;
        BTNode* p = root, *q;
        bool flag;
        do{
            while(p){
                st.push(p);
                p = p -> lchild;
            }
            q = nullptr;
            flag = true;
            while(!st.empty() && flag){
                p = st.top();
                if(p -> rchild == q){
                    cout << p -> data;
                    st.pop();
                    q = p;
                }
                else{
                    p = p -> rchild;
                    flag = false;
                }
            }
        }while(!st.empty());
    }

    void LevelOrder(){
        BTNode* p;
        queue<BTNode*> qu;
        qu.push(root);
        while(!qu.empty()){
            p = qu.front(); qu.pop();
            cout << p -> data;
            if(p -> lchild) qu.push(p -> lchild);
            if(p -> rchild) qu.push(p -> rchild);
        }
    }

    BTNode* CreateBTreeNLR(
        const vector<char>& preorder, 
        const vector<char>& inorder,
        int i, //先序起点
        int j, //中序起点
        int n  //节点总数
    ){
        if(n <= 0) return nullptr;
        char d = preorder[i];
        BTNode* b = new BTNode(d);
        int p = j;
        while(inorder[p] != d) p++; //查找根节点

        int k = p - j; //左子树节点数
        b -> lchild = CreateBTreeNLR(preorder, inorder, i + 1, j, k);
        b -> rchild = CreateBTreeNLR(preorder, inorder, i + k + 1, p + 1, n - k - 1);

        return b;
    }
    void CreateBTreen(vector<char> pres, vector<char> ins){
        int n = pres.size();
        root = CreateBTreeNLR(pres, ins, 0, 0, n);
    }

    BTNode* CreateBTreeLRN(
        const vector<char>& postorder, 
        const vector<char>& inorder,
        int i, //后序起点
        int j, //中序起点
        int n  //节点总数
    ){
        if(n <= 0) return nullptr;
        char d = postorder[i + n - 1];
        BTNode* b = new BTNode(d);
        int p = j;
        while(inorder[p] != d) p++; //查找根节点

        int k = p - j; //左子树节点数
        b -> lchild = CreateBTreeLRN(postorder, inorder, i, j, k);
        b -> rchild = CreateBTreeLRN(postorder, inorder, i + k, p + 1, n - k - 1);

        return b;
    }
    void CreateBTreel(vector<char> pres, vector<char> ins){
        int n = pres.size();
        root = CreateBTreeLRN(pres, ins, 0, 0, n);
    }
};

string PreOrderSeq(BTNode* b){
    if(!b) return "#";
    string s(1, b -> data);
    s += PreOrderSeq(b -> lchild);
    s += PreOrderSeq(b -> rchild);

    return s;
}
string PreOrders(BTree& bt){
    return PreOrderSeq(bt.root);
}

BTNode* ReverseSeqBTree(string s, int& i){
    if(i >= s.length()) return nullptr;
    char d = s[i]; i++;
    if(d == '#') return nullptr;

    BTNode* b = new BTNode(d);
    b -> lchild = ReverseSeqBTree(s, i);
    b -> rchild = ReverseSeqBTree(s, i);

    return b;
}
void ReverseSeq(BTree& bt, string s){
    int i = 0;
    bt.root = ReverseSeqBTree(s, i);
}
