#include <iostream>
using namespace std;

int stk[1000005];
int tt = 0;

const int MaxSize = 1000005;
int cque[MaxSize];
int front = 0;
int rear = 0;
int coun = 0;

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        cque[rear] = x;
        rear = (rear + 1) % MaxSize; 
        coun++;
    }

    for(int i = 0; i < n; ++i){
        stk[tt++] = cque[front];
        front = (front + 1) % MaxSize;
        coun--;
    }

    for(int i = 0; i < n; ++i){
        cque[rear] = stk[--tt];
        rear = (rear + 1) % MaxSize;
        coun++;
    }

    int p = front;
    for(int i = 0; i < n; ++i){
        if(i > 0) cout << " ";
        cout << cque[p];
        p = (p + 1) % MaxSize;
    }

    cout << endl;
    return 0;
}