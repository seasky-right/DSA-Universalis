#include <iostream>
#include <vector>

using namespace std;

int compare(vector<int>& arr, vector<int>& temp,
    int left, int mid, int right) {
    int i = left, j = mid + 1;
    int k = left;
    int count = 0;

    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            count += (mid - i + 1);
        }
    }

    while(i <= mid) temp[k++] = arr[i++];
    while(j <= right) temp[k++] = arr[j++];

    for(int i = left; i <= right; ++i)
        arr[i] = temp[i];

    return count;
}

int Count(vector<int>& arr, vector<int>& temp, int left, int right) {
    if(left >= right) return 0;
    int mid = left + (right - left) / 2;

    int count = 0;

    count += Count(arr, temp, left, mid);
    count += Count(arr, temp, mid + 1, right);

    count += compare(arr, temp, left, mid, right);

    return count;
}

int main() {
    int n; cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; ++i)
        cin >> arr[i];

    vector<int> temp(n);
    cout << Count(arr, temp, 0, n - 1) << endl;

    return 0;
}