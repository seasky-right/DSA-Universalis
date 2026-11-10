#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj;
void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bfs(int s, vector<bool>& visited) {
    queue<int> qu;
    qu.push(s);

    visited[s] = true;
    bool f = true;

    while(!qu.empty()){
        int u = qu.front(); qu.pop();
        if(!f) cout << " ";
        cout << u;
        f = false;

        for(int v : adj[u]) {
            if(!visited[v]) {
                visited[v] = true;
                qu.push(v);
            }
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
    bfs(s, visited);
    cout << endl;

    return 0;
}