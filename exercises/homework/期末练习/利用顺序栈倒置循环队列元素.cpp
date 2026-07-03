#include <iostream>
using namespace std;

const int MAXSIZE = 10005;

int st[MAXSIZE];
int top = -1;

int qu[MAXSIZE];
int front = 0, rear = 0, cnt = 0;

int main() {
    int n; cin >> n;
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        qu[rear] = x;
        rear = (rear + 1) % MAXSIZE;
        cnt++;
    }

    for(int i = 0; i < n; ++i) {
        int x = qu[front];
        front = (front + 1) % MAXSIZE;
        cnt--;

        st[++top] = x;
    }

    for(int i = 0; i < n; ++i) {
        int x = st[top--];

        qu[rear] = x;
        rear = (rear + 1) % MAXSIZE;
        cnt++;
    }

    bool isFirst = true;
    while(cnt != 0) {
        int x = qu[front];
        front = (front + 1) % MAXSIZE;
        cnt--;

        if(!isFirst) cout << " ";
        cout << x;
        isFirst = false;
    }
    cout << endl;

    return 0;
}