#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

priority_queue<int, vector<int>, greater<int>> minHeap;

int main(){
    int n; cin >> n;
    while(n--){
        int op; cin >> op;
        if(op == 1) {
            int x; cin >> x;
            minHeap.push(x);
        }
        else if(op == 2) {
            cout << minHeap.top() << '\n';
        }
        else if(op == 3) {
            if(!minHeap.empty()) minHeap.pop();
        }
    }
    return 0;
}