#include <iostream>

using namespace std;

int stk[1000005];
int tt = 0;

int hstk[1000005];
int htt = 0;

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        stk[tt++] = x;
    }

    while(tt != 0){
        int temp = stk[--tt];
        while(htt > 0 && hstk[htt - 1] < temp){
            stk[tt++] = hstk[--htt];
        }
        hstk[htt++] = temp;
    }

    for(int i = htt; i > 0; --i){
        if(i < htt) cout << " ";
        cout << hstk[i - 1];
    }
    cout << endl;
    return 0;
}
