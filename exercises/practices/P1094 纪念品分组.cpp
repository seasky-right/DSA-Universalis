#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int w, n; cin >> w >> n;
    vector<int> b;
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        b.push_back(x);
    }

    sort(b.begin(), b.end());
    int i = 0, j = b.size() - 1;
    int num = 0;
    while(i <= j) {
        if(b[i] + b [j] <= w) {
            i++; j--;
            num++;
        }
        else {
            num++; j--;
        }
    }

    cout << num << '\n';
    return 0;
}