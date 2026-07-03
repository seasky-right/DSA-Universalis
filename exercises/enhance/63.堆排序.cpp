#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;

    if(left < n && arr[left] > arr[largest]) largest = left;
    if(right < n && arr[right] > arr[largest]) largest = right;

    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void HeapSort(vector<int>& arr) {
    int n = arr.size();

    for(int i = n / 2 - 1; i >= 0; --i)
        heapify(arr, n, i);

    for(int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int n; cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        arr.push_back(x);
    }

    HeapSort(arr);

    bool isFirst = true;
    for(int i = 0; i < n; ++i) {
        if(!isFirst) cout << " ";
        cout << arr[i];
        isFirst = false;
    }
    cout << endl;

    return 0;
}