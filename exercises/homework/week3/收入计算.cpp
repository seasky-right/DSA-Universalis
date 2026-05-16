#include <iostream>
#include <set>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;

    set<int> s;
    long long ans = 0;

    for(int i = 0; i < n; ++i){
        int val;
        cin >> val;
        if(i == 0) ans += val;
        else{
            auto it = s.lower_bound(val);
            long long curr_min = 2e18;

            if(it != s.end()) curr_min = min(curr_min, (long long)abs(*it - val));

            if(it != s.begin()) curr_min = min(curr_min, (long long)abs(*prev(it) - val));

            ans += curr_min;
        }
        s.insert(val);
    }
    cout << ans << endl;
    return 0;
}