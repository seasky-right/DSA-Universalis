#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void BubbleSort(vector<int>& arr){
    int n = arr.size();
    bool swapped = false;

    for(int i = 0; i < n - 1; ++i) {
        swapped = false;
        for(int j = 0; j < n - i - 1; ++j) {
            if(arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
            swapped = true;
        }
        if(!swapped) break;
    }
}

int main() {
    int n; cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        arr.push_back(x);
    }

    BubbleSort(arr);

    bool isFirst = true;
    for(int i = 0; i < n; ++i) {
        if(!isFirst) cout << " ";
        cout << arr[i];
        isFirst = false;
    }
    cout << endl;

    return 0;
}