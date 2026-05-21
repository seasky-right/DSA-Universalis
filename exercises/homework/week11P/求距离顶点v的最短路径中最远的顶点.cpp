#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 1005;
vector<int> adj[N];

void bfs(int v, int n){
    vector<int> dist(n, -1);
    queue<int> q;
    q.push(v);
    dist[v] = 0;

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int w : adj[u]){
            if(dist[w] == -1){
                dist[w] = dist[u] + 1;
                q.push(w);
            }
        }
    }

    int maxDist = -1;
    for(int i : dist){
        if(i > maxDist)
            maxDist = i;
    }

    if(maxDist == 0) {
        cout << "-1" << endl;
        return;
    }

    bool isFirst = true;
    for(int i = 0; i < n; ++i){
        if(dist[i] == maxDist){
            if(!isFirst) cout << " ";
            cout << i;
            isFirst = false;
        } 
    }

    cout << endl;
}

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            int conn; cin >> conn;
            if(conn == 1 && i != j)
                adj[i].push_back(j);
        }
    }

    int v; cin >> v;
    bfs(v, n);

    return 0;
}