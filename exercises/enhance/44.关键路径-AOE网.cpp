#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<pair<int, int>>> adj;
void addEdge(int u, int v, int w) {
    adj[u].push_back({v, w});
}

void CriticalPath(int n) {
    vector<int> indegree(n + 1);
    vector<int> topo_order;
    queue<int> qu;

    for(int u = 1; u <= n; ++u) {
        for(const pair<int, int> p : adj[u]) {
            int v = p.first;
            indegree[v]++;
        }
    }

    for(int u = 1; u <= n; ++u) {
        if(indegree[u] == 0) qu.push(u);
    }

    vector<int> ve(n + 1, 0);
    while(!qu.empty()) {
        int u = qu.front(); qu.pop();
        topo_order.push_back(u);

        for(const pair<int, int> p : adj[u]) {
            int v = p.first;
            int w = p.second;
            indegree[v]--;
            if(indegree[v] == 0) qu.push(v);
            ve[v] = max(ve[v], ve[u] + w);
        }
    }

    if(topo_order.size() != n) cout << -1 << endl;
    else {
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            ans = max(ans, ve[i]);
        }
        cout << ans << endl;
    }
}

int main() {
    int n, m; cin >> n >> m;
    adj.resize(n + 1);
    for(int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        addEdge(u, v, w);
    }

    CriticalPath(n);
    return 0;
}