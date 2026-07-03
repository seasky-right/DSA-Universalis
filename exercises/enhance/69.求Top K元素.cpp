// 最小堆算法
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    
    priority_queue<int, vector<int>, greater<int>> min_heap;

    for(int i = 0; i < n; ++ i) {
        int x; cin >> x;

        if(min_heap.size() < k)
            min_heap.push(x);
        else if(x > min_heap.top()) {
            min_heap.pop();
            min_heap.push(x);
        }
    }

    cout << min_heap.top() << endl;

    return 0;
}