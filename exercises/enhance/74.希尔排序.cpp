#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void ShellSort(vector<int>& arr){
    int n = arr.size();
    
    for(int d = n / 2; d >= 1; d /= 2) {
        for(int i = d; i < n; i += d) {
            int tmp = arr[i];
            int j = i - d;

            while(j >= 0 && arr[j] >= tmp) {
                arr[j + d] = arr[j];
                j -= d;
            }
            arr[j + d] = tmp;
        }
    }
}

int main() {
    int n; cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        arr.push_back(x);
    }

    ShellSort(arr);

    bool isFirst = true;
    for(int i = 0; i < n; ++i) {
        if(!isFirst) cout << " ";
        cout << arr[i];
        isFirst = false;
    }
    cout << endl;

    return 0;
}