#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 1005;
const int INF = 0x3f3f3f3f;
vector<pair<int, int>> adj[N];

void addEdge(int u, int v, int w) {
    adj[u].push_back({v, w});
}

void Dijkstra(int n, int s) {
    vector<int> dist(n + 1, INF); // 起点到节点v的最短路径
    vector<bool> visited(n + 1, false);

    dist[s] = 0;

    for(int i = 0; i < n; ++i) {
        int u = -1;
        int minDist = INF; // 距当前节点u的最短路径

        for(int j = 1; j <= n; ++j) {
            if(!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        if(u == -1) break; // 所有可达节点都已访问
        visited[u] = true;

        for(auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if(!visited[v] && minDist + w < dist[v]) {
                dist[v] = minDist + w;
            }
        }
    }

    bool isFirst = true;
    for(int i = 1; i <= n; ++i) {
        if(!isFirst) cout << " ";
        isFirst = false;
        if(dist[i] == INF) {
            cout << -1;
        } else {
            cout << dist[i];
        }
    }
    cout << endl;
}

void Dijkstra_heap(int n, int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 1, INF);
    vector<bool> visited(n + 1, false);

    dist[s] = 0;
    pq.push({0, s});

    while(!pq.empty()) {
        auto curr = pq.top(); pq.pop();
        int u = curr.second;
        int d = curr.first;
        if(visited[u]) continue;
        visited[u] = true;

        for(auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if(!visited[v] && d + w < dist[v]) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    bool isFirst = true;
    for(int i = 1; i <= n; ++i) {
        if(!isFirst) cout << " ";
        isFirst = false;
        if(dist[i] == INF) {
            cout << -1;
        } else {
            cout << dist[i];
        }
    }
    cout << endl;
}

int main() {
    int n, m, s; cin >> n >> m >> s;
    for(int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        addEdge(u, v, w);
    }

    Dijkstra(n, s);
    return 0;
}