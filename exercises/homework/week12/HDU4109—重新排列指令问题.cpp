#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>

using namespace std;

struct Edge {
    int to;
    int weight;
};

int main() {
    // 显式重定向标准输入到 in.txt
    freopen("in.txt", "r", stdin);

    // 优化标准输入输出流的性能
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    while (cin >> n >> m) {
        vector<vector<Edge>> adj(n);
        vector<int> indegree(n, 0);

        for (int i = 0; i < m; ++i) {
            int x, y, z;
            cin >> x >> y >> z;
            adj[x].push_back({y, z});
            indegree[y]++;
        }

        vector<int> dist(n, 0);
        queue<int> q;

        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (const auto& edge : adj[u]) {
                int v = edge.to;
                int w = edge.weight;
                
                if (dist[v] < dist[u] + w) {
                    dist[v] = dist[u] + w;
                }
                
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        int max_start_time = 0;
        for (int i = 0; i < n; ++i) {
            if (dist[i] > max_start_time) {
                max_start_time = dist[i];
            }
        }

        cout << max_start_time + 1 << "\n";
    }

    return 0;
}