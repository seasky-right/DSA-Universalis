#include <iostream>
#include <stack>

char inSeq[30], outSeq[30];

using namespace std;
int main(){
    int n; cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> inSeq[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> outSeq[i];
    }

    stack<char> s;
    int i = 0, j = 0;
    while(i < n && j < n){
        s.push(inSeq[i]);
        while(!s.empty() && s.top() == outSeq[j]){
            s.pop();
            j++;
        }
        i++;
    }

    if(!s.empty()) cout << "false";
    else cout << "true";

    return 0;
}