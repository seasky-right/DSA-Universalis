#include <iostream>
#include <algorithm>

using namespace std;

struct task{
    int arrival, execution, order;
};

int main(){
    int n; cin >> n;
    task t[n];
    for(int i = 0; i < n; ++i){
        int a, e; cin >> a >> e;
        t[i].arrival = a, t[i].execution = e, t[i].order = i;
    }

    sort(t, t + n, [](const task& a, const task& b){
        if(a.arrival != b.arrival) return a.arrival < b.arrival;
        return a.order < b.order; 
    });

    int ans = 0, currtime = 0;
    for(int i = 0; i < n; ++i){
        ans += max(currtime, t[i].arrival) - t[i].arrival;
        currtime = max(currtime, t[i].arrival) + t[i].execution;
    }

    cout << ans << endl;
    return 0;
}