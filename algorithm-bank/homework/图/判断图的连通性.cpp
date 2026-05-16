#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 1005;
vector<int> adj[N];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs_helper(int u, vector<bool>& visited){
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v]){
            dfs_helper(v, visited);
        }
    }
}
void dfs(int n, vector<bool>& visited){
    int cnt = 0;
    for(int i = 1; i <= n; ++i){
        if(!visited[i]){
            cnt++;
            dfs_helper(i, visited);
        }
    }
    if(cnt == 1) cout << "YES" << endl;
    else cout << "NO " << cnt << endl;
}

void bfs(int n, vector<bool>& visited){
    int cnt = 0;
    for(int i = 1; i <= n; ++i){
        if(!visited[i]){
            cnt++;
            queue<int> qu;
            visited[i] = true;
            qu.push(i);
            while(!qu.empty()){
                int curr = qu.front();
                qu.pop();

                for(int v : adj[curr]){
                    if(!visited[v]){
                        visited[v] = true;
                        qu.push(v);
                    }
                }
            }
        }
    }
    
    if(cnt == 1) cout << "YES" << endl;
    else cout << "NO " << cnt << endl;
}

int main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        addEdge(u, v);
    }

    vector<bool> visited(n, false);
    dfs(n, visited);

    cout << endl;
    return 0;
}