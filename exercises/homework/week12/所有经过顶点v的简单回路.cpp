#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int N = 1005;
vector<int> adj[N];

void addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

set<vector<int>> path;
void backtrack(int u, int v, vector<int>& currentPath, vector<bool>& visited){
    for(int x : adj[u]){
        if(x == v){
            if(currentPath.size() > 1){
                vector<int> temp = currentPath;
                temp.push_back(v);
                sort(temp.begin(), temp.end());
                path.insert(temp);
            }
        }
        else if(!visited[x]){
            visited[x] = true;
            currentPath.push_back(x);

            backtrack(x, v, currentPath, visited);

            currentPath.pop_back();
            visited[x] = false;
        }
    }
}

int main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        addEdge(u, v);
    }

    int v; cin >> v;
    vector<int> currentPath;
    vector<bool> visited(n, false);
    visited[v] = true;
    backtrack(v, v, currentPath, visited);

    if(path.empty()) cout << -1 << endl;
    else {
        for(const auto& p : path){
            for(int i = 0; i < p.size(); ++i){
                if(i > 0) cout << " ";
                cout << p[i];
            }
            cout << endl;
        }
    }

    return 0;
}