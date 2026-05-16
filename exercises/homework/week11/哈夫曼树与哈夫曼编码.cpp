#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int main(){
    int n; cin >> n;
    priority_queue<int, vector<int>, greater<int>> qu;
    for(int i = 0; i < n; ++i){
        int m; cin >> m;
        qu.push(m);
    }

    long long total_wpl = 0;

    while(qu.size() > 1){
        int sum, a, b;
        a = qu.top(); qu.pop();
        b = qu.top(); qu.pop();
        sum = a + b;
        total_wpl += sum;
        qu.push(sum);
    }

    cout << total_wpl << endl;

    return 0;
}