#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(bool& f, int u, vector<bool>& visited) {
    if(visited[u]) return;
    visited[u] = true;
    if(!f) cout << " ";
    cout << u;
    f = false;

    for(int v : adj[u]) {
        if(!visited[v]) {
            dfs(f, v, visited);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }

    int s; cin >> s;

    vector<bool> visited(n + 1, false);
    bool f = true;
    dfs(f, s, visited);
    cout << endl;

    return 0;
}