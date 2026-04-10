#include <iostream>

using namespace std;
int que[1000005];
int front = 5;
int rear = 5;

int main(){
    int n; cin >> n;
    int t = n * (n + 1) / 2 + n;
    que[rear++] = 1;
    for(int j = 0; j < n; ++j){
        que[rear++] = 0;
        que[rear++] = 1;
        bool isFirst = true;
        while(true){
            int temp = que[front++];
            if(temp == 0) break;
            else{
                if(!isFirst) cout << " ";
                cout << temp;
                que[rear++] = temp + que[front];
                isFirst = false;
            }
        }
        cout << endl;
    }
    return 0;
}