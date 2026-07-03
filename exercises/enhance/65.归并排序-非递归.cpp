#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int>& arr, vector<int>& temp,
    int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while(i <= mid && j <= right) {
        if(arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i <= mid) temp[k++] = arr[i++];
    while(j <= right) temp[k++] = arr[j++];

    for(int l = left; l <= right; l++)
        arr[l] = temp[l];
}

void MergeSort(vector<int>& arr) {
    int n = arr.size();
    vector<int> temp(n);

    for(int w = 1; w <= n; w *= 2) {
        for(int l = 0; l < n; l += 2 * w) {
            int mid = min(l + w - 1, n - 1);
            int r = min(l + 2 * w - 1, n - 1);

            if(mid < r)
                merge(arr, temp, l, mid, r);
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

    MergeSort(arr);

    bool isFirst = true;
    for(int i = 0; i < n; ++i) {
        if(!isFirst) cout << " ";
        cout << arr[i];
        isFirst = false;
    }
    cout << endl;

    return 0;
}