#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 1005;
vector<int> adj[N];

void bfs(int u, int v, int n){
    if(u == v){
        cout << "TRUE" << endl;
        return;
    }
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(u); visited[u] = true;

    while(!q.empty()){
        int w = q.front(); q.pop();
        if(w == v){
            cout << "TRUE" << endl;
            return;
        }
        for(int x : adj[w]){
            if(!visited[x]){
                visited[x] = true;
                q.push(x);
            }
        }
    }

    cout << "FALSE" << endl;
}

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            int conn; cin >> conn;
            if(conn == 1 && i != j){
                adj[i].push_back(j);
            }
        }
    }

    int u, v; cin >> u >> v;
    bfs(u, v, n);

    return 0;
}