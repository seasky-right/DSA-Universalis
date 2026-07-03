#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void QuickSort(vector<int>& arr, int low, int high) {
    if(low >= high) return;

    int pivot = arr[low];
    int i = low, j = high;

    while(i < j) {
        while(i < j && arr[j] >= pivot) j--;
        if(i < j) arr[i++] = arr[j];

        while(i < j && arr[i] <= pivot) i++;
        if(i < j) arr[j--] = arr[i];
    }
    arr[i] = pivot;

    QuickSort(arr, low, i - 1);
    QuickSort(arr, i + 1, high);
}

int main() {
    int n; cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        arr.push_back(x);
    }

    int low = 0, high = arr.size() - 1;
    QuickSort(arr, low, high);

    bool isFirst = true;
    for(int i = 0; i < n; ++i) {
        if(!isFirst) cout << " ";
        cout << arr[i];
        isFirst = false;
    }
    cout << endl;

    return 0;
}