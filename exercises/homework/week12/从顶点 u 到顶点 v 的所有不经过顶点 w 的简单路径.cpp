#include <iostream>
#include <vector>

using namespace std;

const int N = 1005;
vector<int> adj[N];

void addEdge(int u, int v){
    adj[u].push_back(v);
};

vector<vector<int>> path;
void dfs(int u, int v, vector<int>& currentPath, vector<bool>& visited){
    visited[u] = true;
    currentPath.push_back(u);

    if(u == v) {
        path.push_back(currentPath);
    }
    else {
        for(int x : adj[u]){
            if(!visited[x]){
                dfs(x, v, currentPath, visited);
            }
        }
    }
    currentPath.pop_back();
    visited[u] = false;
}

int main(){
    int n, m; cin >> n >> m;
    int u, v, w; cin >> u >> v >> w;

    for(int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        addEdge(u, v);
    }

    if(u == w || v == w) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> currentPath;
    vector<bool> visited(n, false);
    visited[w] = true;
    dfs(u, v, currentPath, visited);

    if(path.empty()) cout << -1 << endl;
    else {
        for(const auto& p : path){
            for(int i = 0; i < p. size(); ++i){
                if(i > 0) cout << " ";
                cout << p[i];
            }
            cout << endl;
        }
    }
    return 0;
}