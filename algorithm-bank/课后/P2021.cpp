#include <iostream>
using namespace std;

int que[1000005];
int front = 500000;
int rear = 500000;

int main(){
    int n; cin >> n;
    for(int i = n; i > 0; --i){
        que[--front] = i;
        if(i != n){
            que[--front] = que[--rear];
        }
    }
    bool isFirst = true;
    for(int i = 0; i < n; ++i){
        if(!isFirst) cout << " ";
        cout << que[front + i];
        isFirst = false;
    }
    return 0;
}