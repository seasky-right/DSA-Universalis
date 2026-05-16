#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct HTNode{
    char data;
    double weight;
    int parent;
    int lchild;
    int rchild;
    bool flag; // 1：左节点 0：右节点
    HTNode() : 
        parent(-1), lchild(-1), rchild(-1) {}
    HTNode(char d, double w) :
        data(d), weight(w), parent(-1),
        lchild(-1), rchild(-1), flag(true) {}
};

struct HeapNode{
    int index;
    double weight;
    HeapNode(int i, double w) : index(i), weight(w) {}
    bool operator<(const HeapNode& s) const {
        return weight > s.weight; //小根堆
    }
};

class HuffmanTree{
    HTNode* ht;
    int n; //叶子节点个数

    void CreateHT() {
        priority_queue<HeapNode> qu;
        for(int i = 0; i < n; ++i){
            qu.push(HeapNode(i, ht[i].weight));
        }
    }

};