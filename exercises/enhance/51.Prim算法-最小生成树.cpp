#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 1005;
const int INF = 0x3f3f3f3f;
vector<pair<int, int>> adj[N];

void addEdge(int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

int Prim(int n) {
    vector<int> dist(n + 1, INF);
    vector<bool> visited(n + 1, false);
    dist[1] = 0;

    int totalWeight = 0;

    for(int i = 0; i < n; ++i) {
        int u = -1;
        int minDist = INF;

        for(int j = 1; j <= n; ++j) {
            if(!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        if(u == -1) return -1;
        visited[u] = true;
        totalWeight += minDist;

        for(auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if(!visited[v] && w < dist[v]) {
                dist[v] = w;
            }
        }
    }
    return totalWeight;
}

int Prim_heap(int n) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 1, INF);
    vector<bool> visited(n + 1, false);
    int totalWeight = 0;

    dist[1] = 0;
    pq.push({0, 1});

    int count = 0;
    while(!pq.empty()) {
        auto curr = pq.top(); pq.pop();
        int minDist = curr.first;
        int u = curr.second;
        if(visited[u]) continue;

        count++;
        visited[u] = true;
        totalWeight += minDist;

        for(auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if(!visited[v] && w < dist[v]) {
                dist[v] = w;
                pq.push({w, v});
            }
        }
    }

    if(count != n) return -1; // 图不连通
    return totalWeight;
}

int main() {
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        addEdge(u, v, w);
    }

    cout << Prim(n) << endl;
    return 0;
}