#include <iostream>
using namespace std;

struct mystack{
    int data[1000005];
    int top = 0;

    void push(int x) { data[top++] = x; }

    int pop() {
        int x = data[top];
        top--;
        return x;
    }
};
mystack s;

const int MAXSIZE = 100005;
struct myqueue{
    int data[MAXSIZE];
    int front = 0;
    int tail = 0;
    int count = 0;

    void push(int x){
        data[tail] = x;
        tail = (tail + 1) % MAXSIZE;
        count++;
    }
};
myqueue q;

bool exi[MAXSIZE] = {false};

int main(){
    int n; cin >> n;
    
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        if(x == -1) exi[i] = true;
        else s.push(x);
    }

    for(int i = 0; i < n; ++i){
        if(exi[i]) q.push(-1);
        else q.push(s.pop());
    }

    for(int i = 0; i < n; ++i){
        cout << q.data[(q.front + i) % MAXSIZE] << (i == n - 1 ? "" : " ");
    }
    
    cout << endl;
    return 0;
}
