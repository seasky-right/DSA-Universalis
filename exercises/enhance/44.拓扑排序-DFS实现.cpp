#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;

void addEdge(int u, int v) {
    adj[u].push_back(v);
}

bool dfs(int u, vector<int>& state, vector<int>& order) {
    state[u] = 1;
    for(int v : adj[u]) {
        if(state[v] == 0) {
            if(!dfs(v, state, order)) return false;
        }
        else if(state[v] == 1) {
            return false;
        }
    }
    state[u] = -1;
    order.push_back(u);
    return true;
}
void topSort(int n) {
    vector<int> state(n, 0);
    vector<int> order;

    for(int i = 0; i < n; ++i) {
        if(state[i] == 0) {
            if(!dfs(i, state, order)) {
                cout << -1 << endl;
                return;
            }
        }
    }
    for(int i = order.size() - 1; i >= 0; --i) {
        cout << order[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, m; cin >> n >> m;
    adj.resize(n + 1);
    for(int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        addEdge(u, v);
    }

    topSort(n);
    return 0;
}