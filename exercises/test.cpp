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

void dijkstra(int s, int n) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 1, INF);
    vector<bool> visited(n + 1, false);

    dist[s] = 0;
    pq.push({0, s});

    while(!pq.empty()) {
        auto curr = pq.top(); pq.pop();
        int d = curr.first;
        int u = curr.second;
        if(!visited[u]) continue;
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
}

int main() {
    
}