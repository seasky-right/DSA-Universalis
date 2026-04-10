#include <iostream>
#include <string>
#include <stack>
using namespace std;

void enqueue(stack<int> &s, int a){
    s.push(a);
}

void dequeue(stack<int> &si, stack<int> &so){
    if(so.empty()){
        if(si.empty()){
            cout << "EMPTY" << endl;
            return;
        }
        else{
            while(!si.empty()){
                so.push(si.top());
                si.pop();
            }
        }
    }
    cout << so.top() << endl;
    so.pop();
}

void peek(stack<int> &si, stack<int> &so){
    if(so.empty()){
        if(si.empty()){
            cout << "EMPTY" << endl;
            return;
        }
        else{
            while(!si.empty()){
                so.push(si.top());
                si.pop();
            }
        }
    }
    cout << so.top() << endl;
}

int main(){
    int n;
    cin >> n;
    stack<int> stackin, stackout;
    while(n--){
        string op;
        cin >> op;
        if(op == "ENQUEUE"){
            int x;
            cin >> x;
            enqueue(stackin, x);
        }
        else if(op == "DEQUEUE"){
            dequeue(stackin, stackout);
        }
        else if(op == "PEEK"){
            peek(stackin, stackout);
        }
    }
    return 0;
}