#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void SelectSort(vector<int>& arr){
    int n = arr.size();
    for(int i = 0; i < n; ++i) {
        int min_idx = i; // Laziness
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[min_idx]) min_idx = j;
        }

        if(min_idx != i) swap(arr[i], arr[min_idx]);
    }
}

int main() {
    int n; cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        arr.push_back(x);
    }

    SelectSort(arr);

    bool isFirst = true;
    for(int i = 0; i < n; ++i) {
        if(!isFirst) cout << " ";
        cout << arr[i];
        isFirst = false;
    }
    cout << endl;

    return 0;
}