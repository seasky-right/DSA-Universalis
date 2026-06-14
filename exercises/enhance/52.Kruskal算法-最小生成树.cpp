#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1005;
const int INF = 0x3f3f3f3f;
int parent[N];

struct Edge {
    int u, v;
    int weight;

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};
vector<Edge> edges;

int Find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}
int Kruskal(int n) {
    sort(edges.begin(), edges.end());

    for(int i = 1; i <= n; ++i) parent[i] = i;

    int totalWeight = 0;
    int count = 0;

    for(const auto& edge : edges) {
        int rootU = Find(edge.u);
        int rootV = Find(edge.v);

        if(rootU != rootV) {
            parent[rootU] = rootV;
            totalWeight += edge.weight;
            count++;
            if(count == n - 1) break; // 已经找到n-1条边，生成树完成
        }
    }

    if(count != n - 1) return -1; // 图不连通
    return totalWeight;
}

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    cout << Kruskal(n) << endl;
    return 0;
}
