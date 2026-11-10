#include <iostream>
#include <vector>

using namespace std;

vector<int> line;

int main() {
    int n, m, t;
    cin >> n >> m >> t;
    line.resize(n * m);

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j)
            cin >> line[i * m + j];
    }

    int op;
    while(t--) {
        cin >> op;
        if(op == 1) {
            int p, q; cin >> p >> q;
            line.resize(p * q);

            n = p;
            m = q;
        }
        else if(op == 2) {
            int a, b; cin >> a >> b;
            vector<int> temp(n * m);

            for(int i = 0; i < m; ++i) {
                for(int j = 0; j < n; ++j) {
                    temp[i * n + j] = line[j * m + i];
                }
            }
            line = temp;
        }
        else if(op == 3) {
            int i, j; cin >> i >> j;
            cout << line[i * m + j] << endl;
        }
    }

    return 0;
}