#include <iostream>
#include <vector>
using namespace std;

int getVal(const vector<int>& mat, int i, int j){
    if(i < j) swap(i, j);
    return mat[i * (i + 1) / 2 + j];
}

int main(){
    int n;
    if(!(cin >> n)) return 0;

    int size = n * (n + 1) / 2;
    vector<int> a(size), b(size);

    for(int i = 0; i < size; ++i) cin >> a[i];
    for(int i = 0; i < size; ++i) cin >> b[i];

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            long long sum = 0;
            for(int k = 0; k < n; ++k){
                sum += (long long)getVal(a, i, k) * getVal(b, k, j);
            }
            cout << sum << (j == n - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}