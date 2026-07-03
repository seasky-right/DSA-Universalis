#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void InsertSort(vector<int>& arr){
    int n = arr.size();
    for(int i = 1; i < n; ++i) {
        int tmp = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] >= tmp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = tmp;
    }
}

int main() {
    int n; cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        arr.push_back(x);
    }

    InsertSort(arr);

    bool isFirst = true;
    for(int i = 0; i < n; ++i) {
        if(!isFirst) cout << " ";
        cout << arr[i];
        isFirst = false;
    }
    cout << endl;

    return 0;
}