#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n; 
    if (!(cin >> n)) return 0;
    unordered_set<int> seen;
    bool isFirst = true;
    for(int i = 0; i < n; ++i){
        int x;cin >> x;
        if(seen.count(x) == 0){
            if(!isFirst) cout << " ";
            cout << x;
            seen.insert(x);
            isFirst = false;
        }
    }

    cout << endl;
    return 0;
}