#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>

using namespace std;

const int INF = 1e9; // 定义无限大距离

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        // 构建邻接表，u -> (v, w)
        vector<vector<pair<int, int>>> adj(N + 1);
        for (const auto& edge : times) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        // dist[i] 表示从源点 K 到节点 i 的最短信号到达时间
        vector<int> dist(N + 1, INF);
        // 小根堆，存储结构为 pair<当前距离, 节点编号>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // 初始化源点
        dist[K] = 0;
        pq.push({0, K});

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            // 剪枝：如果当前弹出的距离已经大于已知最短距离，跳过
            if (d > dist[u]) continue;

            // 遍历当前节点的所有邻居
            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int w = neighbor.second;
                
                // 松弛操作
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        // 寻找所有节点中最长的最短路径
        int max_delay = 0;
        for (int i = 1; i <= N; ++i) {
            if (dist[i] == INF) {
                return -1; // 存在无法到达的节点
            }
            max_delay = max(max_delay, dist[i]);
        }

        return max_delay;
    }
};

int main() {
    // 显式重定向标准输入到 in.txt
    freopen("in.txt", "r", stdin);

    // 优化标准输入输出流的性能
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    if (cin >> N >> K) {
        vector<vector<int>> times;
        int u, v, w;
        // 循环读取剩余的每一行边信息直到文件结束
        while (cin >> u >> v >> w) {
            times.push_back({u, v, w});
        }

        Solution solution;
        cout << solution.networkDelayTime(times, N, K) << "\n";
    }

    return 0;
}