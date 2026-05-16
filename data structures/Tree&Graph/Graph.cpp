#include <iostream>
using namespace std;

const int MAXV = 100;
const int INF = 0x3f3f3f3f;
//邻接矩阵
class MatGraph {
private:
    int edges[MAXV][MAXV];
    int n, e;
    string vexs[MAXV];
public:
    void CreateMatGrauph(int a[][MAXV], int n, int e){
        this -> n = n; this -> e = e;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                edges[i][j] = a[i][j];
            }
        }
    }
};

//邻接表
struct EdgeNode{
    int adjvex;
    int weight;
    EdgeNode* next;
};

struct VNode{
    char data;
    EdgeNode* firstedge;
};

class AdjGraph{
    VNode adjlist[MAXV];
    int n, e;
public:
    AdjGraph(){
        for(int i = 0; i < n; ++i)
            adjlist[i].firstedge = nullptr;
    }

    ~AdjGraph(){
        EdgeNode* pre, *p;
        for(int i = 0; i < n; ++i){
            pre = adjlist[i].firstedge;
            if(pre){
                p = pre -> next;
                while(p){
                    delete pre;
                    pre = p; p = p -> next;
                }
                delete pre;
            }
        }
    }

    void CreateAdjGraph(int a[][MAXV], int n, int e){
        EdgeNode* p;
        this -> n = n; this -> e = e;
        for(int i = 0; i < n; ++i){
            for(int j = n - 1; j >= 0; --j){
                if(a[i][j] != 0 && a[i][j] != INF){
                    p = new EdgeNode();
                    p -> adjvex = j; p -> weight = a[i][j];
                    p -> next = adjlist[i].firstedge;
                    adjlist[i].firstedge = p;
                }
            }
        }
    }

    void DispAdjGraph(){
        EdgeNode* p;
        for(int i = 0; i < n; ++i){
            cout << adjlist[i].data << ": ";
            p = adjlist[i].firstedge;
            if(p) cout << "->";
            while(p){
                cout << adjlist[p -> adjvex].data << " ";
                p = p -> next;
            }
            cout << endl;
        }
    }
};