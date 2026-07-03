#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int QuickSelect(vector<int>& arr, int k, int low, int high) {
    if(low >= high) return arr[low];

    int pivot = arr[low];
    int i = low, j = high;

    while(i < j) {
        while(i < j && arr[j] <= pivot) j--;
        if(i < j) arr[i++] = arr[j];

        while(i < j && arr[i] >= pivot) i++;
        if(i < j) arr[j--] = arr[i];
    }
    arr[i] = pivot;
    if(i == k) return pivot;
    else {
        if(i < k) return QuickSelect(arr, k, i + 1, high);
        else return QuickSelect(arr, k, low, i - 1);
    }
}

int main() {
    int n, k; cin >> n >> k;

    vector<int> arr(n, 0);
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        arr[i] = x;
    }

    cout << QuickSelect(arr, k - 1, 0, n - 1) << endl;
    return 0;
}