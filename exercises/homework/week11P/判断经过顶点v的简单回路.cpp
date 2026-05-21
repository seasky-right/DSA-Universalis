#include <iostream>
#include <vector>
using namespace std;

const int N = 1005;
vector<int> adj[N];

void dfs(int u, vector<bool>& visited){
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v]){
            dfs(v, visited);
        }
    }
}
bool existPath(int v, vector<bool>& visited){
    visited[v] = true;
    for(int u : adj[v]){
        if(!visited[u])
            dfs(u, visited);
        else return true;
    }
    return false;
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
    vector<bool> visited(n, false);

    if(existPath(v, visited))
        cout << "TRUE" << endl;
    else
        cout << "FALSE" << endl;

    return 0;

}