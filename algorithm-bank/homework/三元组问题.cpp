#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v1(n), v2(m), v3(k);
    for(int i = 0; i < n; ++i) cin >> v1[i];
    for(int j = 0; j < m; ++j) cin >> v2[j];
    for(int o = 0; o < k; ++o) cin >> v3[o];

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    sort(v3.begin(), v3.end());

    int i = 0, j = 0, o = 0;
    long long min_D = 8e18;

    while(i < n && j < m && o < k){
        int a = v1[i], b = v2[j], c = v3[o];
        long long cur_min = min({a, b, c});
        long long cur_max = max({a, b, c});
        long long cur_D = 2LL * (cur_max - cur_min);

        if(cur_D < min_D) min_D = cur_D;

        if(cur_min == a) i++;
        else if(cur_min == b) j++;
        else o++;
    }

    cout << min_D << endl;
    return 0;
}

// 三指针法（贪心算法）