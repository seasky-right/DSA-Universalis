#include <iostream>
using namespace std;

int nxt[100005] = {0};

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        int val, nxt_i;
        cin >> val >> nxt_i;
        nxt[i] = nxt_i;
    }

    if(n == 0){
        cout << "NO" << endl;
        return 0;
    }

    int slow = 1, fast = 1;
    while(fast != -1 && nxt[fast] != -1){
        slow = nxt[slow];
        fast = nxt[nxt[fast]];
        if(slow == fast){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}