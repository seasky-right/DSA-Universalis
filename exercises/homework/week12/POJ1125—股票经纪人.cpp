#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

const int INF = 1e9; // 设为一个足够大的正无穷值

int main() {
    // 显式重定向标准输入到 in.txt
    freopen("in.txt", "r", stdin);

    // 优化标准输入输出流性能
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // 循环读取每组数据的节点数 n，当 n 为 0 时输入结束
    while (cin >> n && n != 0) {
        // 初始化邻接矩阵，点编号从 1 到 n
        vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
        for (int i = 1; i <= n; ++i) {
            dist[i][i] = 0;
        }

        // 读取图的边信息
        for (int i = 1; i <= n; ++i) {
            int m;
            cin >> m;
            for (int j = 0; j < m; ++j) {
                int target, weight;
                cin >> target >> weight;
                dist[i][target] = weight;
            }
        }

        // Floyd-Warshall 算法计算任意两点间的最短路径
        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        int min_max_dist = INF;
        int best_source = -1;

        // 遍历每个潜在的起点，找到扩散到所有人所需时间最短的那个
        for (int i = 1; i <= n; ++i) {
            int current_max = 0;
            bool can_reach_all = true;
            
            for (int j = 1; j <= n; ++j) {
                if (dist[i][j] == INF) { // 存在无法到达的人
                    can_reach_all = false;
                    break;
                }
                current_max = max(current_max, dist[i][j]);
            }

            // 如果能传给所有人，且当前最长耗时比已知全局最长耗时更短，则更新
            if (can_reach_all && current_max < min_max_dist) {
                min_max_dist = current_max;
                best_source = i;
            }
        }

        // 输出结果
        if (best_source == -1) {
            cout << "disjoint\n";
        } else {
            cout << best_source << " " << min_max_dist << "\n";
        }
    }

    return 0;
}