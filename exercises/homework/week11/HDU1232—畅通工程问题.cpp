#include <iostream>
#include <fstream>
using namespace std;

int parent[10005] = {0};

void Init(int n){
    for(int i = 1; i <= n; ++i){
        parent[i] = i;
    }
}

int Find(int x){
    if(parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int i, int j, int& n){
    int rooti = Find(i);
    int rootj = Find(j);

    if(rooti != rootj){
        parent[rooti] = rootj;
        n--;
    }
}

int main(){
    ifstream in("in.txt");
    int n, m; in >> n >> m;
    Init(n);
    while(m--){
        int i, j; in >> i >> j;
        Union(i, j, n);
    }

    cout << n - 1 << endl;
    return 0;
}