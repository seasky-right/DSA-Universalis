#include <iostream>
#include <vector>

using namespace std;

vector<int> line;
vector<vector<int>> matrix;

int main() {
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    line.resize(n * m);
    matrix.resize(p, vector<int>(q));

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j)
            cin >> line[i * m + j];
    }

    for(int i = 0; i < p; ++i) {
        for(int j = 0; j < q; ++j)
            matrix[i][j] = line[i * q + j];
    }

    for(int i = 0; i < p; ++i) {
        for(int j = 0; j < q; ++j) {
            cout << matrix[i][j];
            if(j != q - 1)
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}