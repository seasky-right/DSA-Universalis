#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 10005;
const int INF = 0x3f3f3f3f;
vector<pair<int, int>> adj[N];
void addEdge(int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

void dijkstra(int n, int s, int t) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 1, INF);
    vector<bool> visited(n + 1, false);
    vector<int> pre(n + 1, -1); // 利用前驱节点存储路径

    dist[s] = 0; 
    pq.push({0, s});

    while(!pq.empty()) {
        auto curr = pq.top(); pq.pop();
        int d = curr.first;
        int u = curr.second;
        if(visited[u]) continue;
        visited[u] = true;

        for(auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if(!visited[v] && d + w < dist[v]) {
                dist[v] = d + w;
                pq.push({dist[v], v});
                pre[v] = u; // 每次松弛更新前驱
            }
        }
    }

    cout << dist[t] << '\n';

    if (dist[t] == INF) {
        cout << -1 << '\n';
        return;
    }

    vector<int> path;
    for(int v = t; v != -1; v = pre[v]) 
        path.push_back(v);

    reverse(path.begin(), path.end());
    for(size_t i = 0; i < path.size(); ++i)
        cout << path[i] << ' ';

    cout << '\n';
}