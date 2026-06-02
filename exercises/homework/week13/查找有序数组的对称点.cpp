#include <iostream>
#include <vector>
using namespace std;

bool BinSearch(const vector<int>& arr, int l, int r) {
    while(l <= r) {
        int mid = l + (r - l) / 2;

        if(arr[mid] == mid) return true;
        else if(arr[mid] < mid) l = mid + 1;
        else r = mid - 1;
    }

    return false;
}

int main() {
    int n; cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; ++i)
        cin >> arr[i];

    int low = 0, high = n - 1;
    cout << (BinSearch(arr, low, high) ? "Yes" : "No") << endl;
    return 0;
}