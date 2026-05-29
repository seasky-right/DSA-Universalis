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

// 普里姆算法
int Prim(const int a[][MAXV], int n, int start){
    vector<int> lowcost(n, INF);
    vector<int> closest(n, -1);

    for(int i = 0; i < n; ++i){
        lowcost[i] = a[start][i];
        closest[i] = start;
    }
    lowcost[start] = 0;

    int totalWeight = 0;

    for(int i = 1; i < n; ++i){
        int mincost = INF;
        int k = -1;

        for(int j = 0; j < n; ++j){
            if(lowcost[j] != 0 && lowcost[j] < mincost){
                mincost = lowcost[j];
                k = j;
            }
        }

        if(k == -1) return -1; //图不连通

        totalWeight += mincost;
        lowcost[k] = 0; //进入生成树

        for(int j = 0; j < n; ++j){
            if(lowcost[j] != 0 && a[k][j] < lowcost[j]){
                lowcost[j] = a[k][j];
                closest[j] = k;
            }
        }
    }

    return totalWeight;
}

// 克鲁斯卡尔算法
struct Edge {
    int u, v;
    int weight;

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

int Find(int parent[], int x) {
    if(parent[x] == x) return x;
    return parent[x] = Find(parent, parent[x]);
}
int Kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());

    vector<int> parent(n);
    for(int i = 0; i < n; ++i) parent[i] = i;

    int totalWeight = 0;
    int edgeCount = 0;

    for(const auto& edge : edges) {
        int rootU = Find(parent.data(), edge.u);
        int rootV = Find(parent.data(), edge.v);

        if(rootU != rootV) {
            parent[rootU] = rootV;
            totalWeight += edge.weight;
            edgeCount++;
            if(edgeCount == n - 1) break; // 已经找到n-1条边，生成树完成
        } else {
            // 这条边会形成环，跳过
        }
    }

    if(edgeCount != n - 1) return -1; // 图不连通
    return totalWeight;
}

//迪杰斯特拉算法
int Dijkstra(const int a[][MAXV], int n, int start, int end) {
    vector<int> dist(n, INF); // 节点到树的垂直距离
    vector<int> path(n, -1); // 最短路径树（父表示法）
    vector<bool> visited(n, false);
    
    dist[start] = 0;

    for(int i = 0; i < n; ++i) {
        int u = -1;
        int minDist = INF;

        for(int j = 0; j < n; ++j) {
            if(!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        if(u == -1) break; // 所有可达节点都已访问

        visited[u] = true;

        // 松弛
        for(int v = 0; v < n; ++v) {
            if(a[u][v] != 0 && a[u][v] != INF && !visited[v]) {
                if(dist[u] + a[u][v] < dist[v]) {
                    dist[v] = dist[u] + a[u][v];
                    path[v] = u;
                }
            }
        }
    }

    return dist[end] == INF ? -1 : dist[end];
}

int Floyd(const vector<vector<int>>& graph, int start, int end) {
    vector<vector<int>> dist = graph;
    int n = graph.size();
    vector<vector<int>> path(n, vector<int>(n, -1));

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(i != j && dist[i][j] != 0 && dist[i][j] != INF){
                path[i][j] = i;
            }
        }
    }

    for(int k = 0; k < n; ++k){
        for(int i = 0; i < n; ++i){
            if(dist[i][k] == INF) continue; // 跳过不可达的中间节点
            for(int j = 0; j < n; ++j){
                if(dist[k][j] == INF) continue; // 跳过不可达的终点
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = k;
                }
            }
        }
    }

    return dist[start][end];
}

//拓扑排序
bool TopSort(int n, const vector<vector<int>>& graph) {
    vector<int> indegree(n, 0);
    vector<int> topo_order;
    stack<int> st; // 存储入度为0的节点
    int count = 0;

    for(int u = 0; u < n; ++u){
        for(int v : graph[u]){
            indegree[v]++;
        }
    }

    for(int i = 0; i < n; ++i){
        if(indegree[i] == 0)
            st.push(i);
    }

    while(!st.empty()){
        int u = st.top(); st.pop();
        topo_order.push_back(u);
        count++;

        for(int v : graph[u]){
            indegree[v]--;
            if(indegree[v] == 0)
                st.push(v);
        }
    }

    if(count == n) return true; // 有向无环图
    return false; // 存在环
}

struct Edge {
    int to;
    int weight;
};
bool CriticalPath(int n, const vector<vector<Edge>>& graph) {
    vector<int> indegree(n, 0);
    vector<int> topo_order;
    stack<int> st;

    for(int u = 0; u < n; ++u){
        for(const auto& edge : graph[u]){
            indegree[edge.to]++;
        }
    }

    for(int i = 0; i < n; ++i){
        if(indegree[i] == 0)
            st.push(i);
    }

    // ==========================================
    // 【阶段 1】：顺流而下求 ve 
    // ==========================================
    vector<int> ve(n, 0); // ve[i]：事件 i 的最早发生时间
    while(!st.empty()){
        int u = st.top(); st.pop();
        topo_order.push_back(u);

        for(const auto& edge : graph[u]){
            int v = edge.to;
            int w = edge.weight;
            ve[v] = max(ve[v], ve[u] + w); // 更新事件 v 的最早发生时间
            indegree[v]--;
            if(indegree[v] == 0)
                st.push(v);
        }
    }

    if(topo_order.size() != n) return false; // 存在环

    // ==========================================
    // 【阶段 2】：逆流而上求 vl
    // ==========================================
    int max_total_time = *max_element(ve.begin(), ve.end()); // 项目总工期
    vector<int> vl(n, max_total_time); // vl[i]：事件 i 的最晚发生时间，初始值为项目总工期

    for(int i = topo_order.size() - 1; i >= 0; --i){
        int u = topo_order[i];
        for(const auto& edge : graph[u]){
            int v = edge.to;
            int w = edge.weight;
            vl[u] = min(vl[u], vl[v] - w); // 更新事件 u 的最晚发生时间
        }   
    }

    // ==========================================
    // 【阶段 3】：找关键活动
    // ==========================================
    vector<pair<int, int>> critical_activities; // 存储关键活动 (u, v)
    for(int u = 0; u < n; ++u){
        for(const auto& edge : graph[u]){
            int v = edge.to;   
            int w = edge.weight;
            int ee = ve[u]; // 活动 (u, v) 的最早开始
            int el = vl[v] - w; // 活动 (u, v) 的最晚开始
            if(ee == el){
                critical_activities.push_back({u, v});
            }
        }
    }

    return true;
}