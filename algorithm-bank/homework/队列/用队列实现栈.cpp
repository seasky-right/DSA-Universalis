#include <iostream>
#include <queue>

using namespace std;

void push(queue<int>& q, int x){
    int n = q.size();
    q.push(x);
    for(int i = 0; i < n; ++i){
        q.push(q.front());
        q.pop();
    }
}

int pop(queue<int>& q){
    if(q.empty()){
        return -1;
    }
    int n = q.front();
    q.pop();
    return n;
}

int top(queue<int> q){
    if(q.empty()){
        return -1;
    }
    int n = q.front();
    return n;
}

int main(){
    int n;
    cin >> n;
    queue<int> q;
    while(n--){
        string op;
        cin >> op;
        if(op == "PUSH"){
            int x;
            cin >> x;
            push(q, x);
        }
        else if(op == "POP"){
            cout << pop(q) << endl;
        }
        else if(op == "TOP"){
            cout << top(q) << endl;
        }
    }
    return 0;
}