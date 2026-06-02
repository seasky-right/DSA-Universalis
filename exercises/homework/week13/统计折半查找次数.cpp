#include <iostream>
#include <vector>

using namespace std;

int BinSearch(const vector<int>& arr, int l, int r, int key) {
    int count = 0;

    // lower_bound实现：找到第一个不小于key的元素位置
    while(l < r) {
        int mid = l + (r - l) / 2;
        count++;
        if(arr[mid] < key) l = mid + 1;
        else r = mid;
    }

    if(arr[l] == key) return count;
    else return -1;
}

int main() {
    int n, k; cin >> n >> k;
    vector<int> arr(n);

    for(int i = 0; i < n; ++i)
        cin >> arr[i];

    int low = 0, high = n - 1;

    cout << BinSearch(arr, low, high, k) << endl;
    return 0;
}