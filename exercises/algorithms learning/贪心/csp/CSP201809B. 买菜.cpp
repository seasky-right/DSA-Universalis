#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> H, W;
    for(int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b;
        H.push_back({a, b});
    }
    for(int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b;
        W.push_back({a, b});
    }

    int ans = 0, left = 0, right = 0;
    int i = 0, j = 0;
    while(i < n && j < n) {
        left = max(H[i][0], W[j][0]);
        right = min(H[i][1], W[j][1]);

        if(right > left) ans += right - left;

        if(H[i][1] > W[j][1]) j++;
        else if (W[j][1] > H[i][1]) i++;
        else {
            i++; j++;
        }
    }

    cout << ans << '\n';
    return 0;
}