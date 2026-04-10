#include <iostream>

using namespace std;

class Seqstack{
public:
    int* data;
    int top;
    int cap;

    Seqstack(int n){
        cap = n;
        top = -1;
        data = new int[n];
    }

    void push(int x){
        if(top == cap - 1){
            cout << "FULL" << endl;
            return;
        }
        data[++top] = x;
    }

    void pop(){
        if(top == -1){
            cout << "EMPTY" << endl;
            return;
        }
        cout << data[top--] << endl;
    }

    void topf(){
        if(top == -1){
            cout << "EMPTY" << endl;
            return;
        }
        cout << data[top] << endl;
    }

    void size(){
        cout << top + 1 << endl;
    }

};

int main(){
    int n, m;
    cin >> n >> m;
    string str;
    Seqstack s(n);
    while(m--){
        cin >> str;
        if(str == "PUSH"){
            int x; cin >> x;
            s.push(x);
        }else if(str == "TOP"){
            s.topf();
        }else if(str == "POP"){
            s.pop();
        }else if(str == "SIZE"){
            s.size();
        }
    }

    return 0;
}