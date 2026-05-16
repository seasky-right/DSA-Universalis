#include <iostream>
using namespace std;


struct BthNode{
    char data;
    BthNode* lchild, *rchild;
    bool ltag, rtag; // 0: child pointer, 1: thread pointer
    BthNode() {}
    BthNode(char d) : 
        data(d), lchild(nullptr), rchild(nullptr), ltag(0), rtag(0) {}
};

class ThreadTree{
    BthNode* r;
    BthNode* root;
    BthNode* pre;

public:
    ThreadTree() : r(nullptr), root(nullptr), pre(nullptr) {}

    void Destroy(BthNode* p) {
        if (p) {
            if (!p->ltag) Destroy(p->lchild);
            if (!p->rtag) Destroy(p->rchild);
            delete p;
        }
    }
    ~ThreadTree() {
        if(r) Destroy(r);
        if(root) delete root;
    }

    void Thread(BthNode*& p){
        if(p){
            Thread(p -> lchild);
            if(!p -> lchild){
                p -> lchild = pre;
                p -> ltag = 1;
            }
            else p -> ltag = 0;
            if(!pre -> rchild){
                pre -> rchild = p;
                pre -> rtag = 1;
            }
            else pre -> rtag = 0;
            pre = p;
            Thread(p -> rchild);
        }
    }
    void CreateThread(){
        root = new BthNode();
        root -> ltag = 0; root -> rtag = 1;
        root -> rchild = r;
        if(!r){
            root -> lchild = root;
            root -> rchild = nullptr;
        }
        else{
            root -> lchild = r;
            pre = root;
            Thread(r);
            pre -> rchild = nullptr;
            pre -> rtag = 1;
            root -> rchild = pre;
        }
    }

    void InOrder(){
        BthNode* p = root -> lchild;
        while(p != root){
            while(p != root && !p -> ltag) p = p -> lchild;
            cout << p -> data;
            while(p -> rtag && p -> rchild != root){
                p = p -> rchild;
                cout << p -> data;
            }
            p = p -> rchild;
        }
    }
};