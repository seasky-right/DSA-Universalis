#include <iostream>
#include <vector>
using namespace std;

const int N = 1005;
vector<int> adj[N];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs_helper(int u, vector<bool>& visited){
    visited[u] = true;
    for(int v : adj[u]) {
        if(!visited[v]){
            dfs_helper(v, visited);
        }
    }
}
int dfs(int n, vector<bool>& visited){
    int cnt = 0;
    for(int i = 1; i <= n; ++i){
        if(!visited[i]){
            cnt++;
            dfs_helper(i, visited);
        }
    }
    return cnt;
}

int main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        addEdge(u, v);
    }

    vector<bool> visited(n + 1, false);
    cout << dfs(n, visited) << endl;

    return 0;
}