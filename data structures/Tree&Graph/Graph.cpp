#include <iostream>
#include <vector>
#include <stack>
#include <queue>
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

//链式前向星（静态数组实现）表示邻接表
struct Edge{
    int adjvex;
    int weight;
    int next;
}edges[MAXV * MAXV];

int n; //顶点数
int cnt; //edges数组中边的数量

int head[MAXV]; //head[i]指向第i个顶点的第一条边在edges数组中的位置

void addedge(int u, int v, int w){
    edges[cnt].adjvex = v;
    edges[cnt].weight = w;
    edges[cnt].next = head[u];
    head[u] = cnt++;
}

void init(){
    cnt = 0;
    for(int i = 0; i < n; ++i)
        head[i] = -1;
}

void CreateAdjGraph(int a[][MAXV], int n, int e){
    init();
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(a[i][j] != 0 && a[i][j] != INF)
                addedge(i, j, a[i][j]);
        }
    }
}

void DispAdjGraph(){
    for(int i = 0; i < n; ++i){
        cout << i << ": ";
        for(int j = head[i]; j != -1; j = edges[j].next){
            cout << edges[j].adjvex << " ";
        }
        cout << endl;
    }
}

//动态数组表示邻接表
struct Edge{
    int adjvex;
    int weight;
};
vector<vector<Edge>> adjlist(MAXV);

//vector数组实现（无向）邻接表
vector<int> adj[MAXV];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

//深度优先遍历
bool visited[MAXV];
void dfs_adj(int u){
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v])
            dfs_adj(v);
    }
}

void dfs_mat(int u, int a[][MAXV]){
    visited[u] = true;
    for(int v = 0; v < n; ++v){
        if(a[u][v] != 0 && a[u][v] != INF && !visited[v]){
            dfs_mat(v, a);
        }
    }
}

void bfs_adj(int u){
    vector<bool> visited(n, false);
    queue<int> q;
    visited[u] = true;
    q.push(u);
    while(!q.empty()){
        int curr = q.front(); q.pop();
        for(int v : adj[curr]){
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void bfs_mat(int u, int a[][MAXV]){
    vector<bool> visited(n, false);
    queue<int> q;
    visited[u] = true;
    q.push(u);
    while(!q.empty()){
        int curr = q.front(); q.pop();
        for(int v = 0; v < n; ++v){
            if(a[curr][v] != 0 && a[curr][v] != INF && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

//回溯法
vector<vector<int>> res;
void backtrack(int level, vector<int>& path, vector<bool>& used){
    if(level == n){
        res.push_back(path);
        return;
    }
    for(int i = 0; i < n; ++i){
        if(!used[i]){ //剪枝
            continue;
        }
        
        path.push_back(i);
        used[i] = true;
        
        backtrack(level + 1, path, used);

        path.pop_back();
        used[i] = false;
    }
}


