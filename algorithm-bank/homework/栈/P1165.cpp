#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n; cin >> n;
    stack<int> s, m;
    for(int i = 0; i < n; ++i){
        int op; cin >> op;
        if(op == 0){
            int x; cin >> x;
            s.push(x);
            if(m.empty() || x > m.top()) m.push(x);
        }else if(op == 1){
            if(!m.empty() && (s.empty() || m.top() == s.top())) m.pop();
            if(!s.empty()) s.pop();
        }else if(op == 2){
            if(s.empty()) cout << 0 << endl;
            else cout << m.top() << endl;
        }
    }

    return 0;
}