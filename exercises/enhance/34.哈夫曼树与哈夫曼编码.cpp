#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int n; cin >> n;
    priority_queue<int, vector<int>, greater<int>> qu;
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        qu.push(x);
    }

    int total_wpl = 0;
    while(qu.size() > 1) {
        int a = qu.top(); qu.pop();
        int b = qu.top(); qu.pop();
        int sum = a + b;
        total_wpl += sum;
        qu.push(sum);
    }

    cout << total_wpl << endl;
    return 0;
}