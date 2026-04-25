#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    
    if (m != n) {
        cout << "false" << endl;
        return 0;
    }
    
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    
    int sum = 0;
    for (int i = 0; i < m; ++i) {
        sum += a[i][i] + a[i][n - 1 - i];
    }
    
    cout << "true " << sum << endl;
    
    return 0;
}
