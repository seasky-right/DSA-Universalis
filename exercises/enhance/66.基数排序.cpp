#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void RadixSort(vector<int>& arr) {
    int n = arr.size();

    int maxVal = 0;
    for(int i = 0; i < n; ++i) {
        maxVal = max(arr[i], maxVal);
    }

    queue<int> buckets[10];

    for(int exp = 1; maxVal / exp > 0; exp *= 10) {
        for(int i = 0; i < n; ++i) {
            int digit = (arr[i] / exp) % 10;
            buckets[digit].push(arr[i]);
        }

        int index = 0;
        for(int i = 0; i < 10; ++i) {
            while(!buckets[i].empty()) {
                arr[index++] = buckets[i].front();
                buckets[i].pop();
            }
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

    RadixSort(arr);

    bool isFirst = true;
    for(int i = 0; i < n; ++i) {
        if(!isFirst) cout << " ";
        cout << arr[i];
        isFirst = false;
    }
    cout << endl;

    return 0;
}