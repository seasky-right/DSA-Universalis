#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
int weight[105][105];
int dist[105][105];

int main(){
    ifstream in("in.txt");
    int n, m; in >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(i == j){
                weight[i][j] = 0;
                dist[i][j] = 0;
            }
            else{
                weight[i][j] = INF;
                dist[i][j] = INF;
            }
        }
    }

    for(int i = 1; i <= m; ++i){
        int u, v, w; in >> u >> v >> w;
        if(w < weight[u][v]){
            weight[u][v] = weight[v][u] = w;
            dist[u][v] = dist[v][u] = w;
        }
    }

    int min_cost = INF;

    for(int k = 1; k <= n; ++k){

        for(int i = 1; i < k; ++i){
            for(int j = i + 1; j < k; ++j){
                if(dist[i][j] != INF && weight[i][k] != INF && weight[k][j] != INF){
                    min_cost = min(min_cost, dist[i][j] + weight[i][k] + weight[k][j]);
                }
            }
        }

        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(dist[i][k] != INF && dist[k][j] != INF){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    if(min_cost == INF) cout << "It's impossible." << endl;
    else cout << min_cost << endl;

    return 0;
}