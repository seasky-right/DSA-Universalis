#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> prerequisites;
void addEdge(int u, int v) {
    prerequisites[v].push_back(u);
}

void TopSort(int n) {
    vector<int> indegree(n, 0);
    vector<int> topOrder;
    queue<int> qu;
    int count= 0;

    for(int u = 0; u < n; u++)
        for(int v : prerequisites[u])
            indegree[v]++;

    for(int u = 0; u < n; ++u)
        if(indegree[u] == 0) qu.push(u);

    while(!qu.empty()) {
        int u = qu.front(); qu.pop();
        topOrder.push_back(u);
        count++;

        for(int v : prerequisites[u]) {
            indegree[v]--;
            if(indegree[v] == 0) qu.push(v);
        }
    }
    
    if(count == n) {
        bool isFirst = true;
        for(size_t i = 0; i < topOrder.size(); ++i) {
            if(!isFirst) cout << " ";
            cout << topOrder[i];
            isFirst = false;
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}

int main() {
    int n, m; cin >> n >> m;
    prerequisites.resize(n);

    while(m--) {
        int a, b; cin >> a >> b;
        addEdge(a, b);
    }

    TopSort(n);
    return 0;
}

// 注意1-base