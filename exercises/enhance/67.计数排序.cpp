#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void CountingSort(vector<int>& arr) {
    int maxVal = arr[0], minVal = arr[0];
    for(int x : arr) {
        if(x > maxVal) maxVal = x;
        if(x < minVal) minVal = x;
    }
    int range = maxVal - minVal + 1;

    vector<int> count(range, 0);
    for(int x : arr) {
        count[x - minVal]++;
    }

    for(int i = 1; i < range; ++i) {
        count[i] += count[i - 1];
    }

    vector<int> temp(arr.size());
    for(int i = arr.size() - 1; i >= 0; --i) {
        int val = arr[i];
        int pos = count[val - minVal] - 1;
        temp[pos] = val;
        count[val - minVal]--;
    }

    arr = temp;
}

int main() {
    int n; cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        arr.push_back(x);
    }

    CountingSort(arr);

    bool isFirst = true;
    for(int i = 0; i < n; ++i) {
        if(!isFirst) cout << " ";
        cout << arr[i];
        isFirst = false;
    }
    cout << endl;

    return 0;
}