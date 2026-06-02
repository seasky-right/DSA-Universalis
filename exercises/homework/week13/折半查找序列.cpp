#include <iostream>
#include <vector>
using namespace std;

void BinSearch(const vector<int>& arr, vector<int>& res, int low, int high, int key) {
    if(low > high) return;

    int mid = low + (high - low) / 2;
    res.push_back(arr[mid]);

    if(arr[mid] == key) return;
    else if(arr[mid] < key)
        BinSearch(arr, res, mid + 1, high, key);
    else
        BinSearch(arr, res, low, mid - 1, key);
}

int main() {
    int n; 
    if(!(cin >> n)) return 0;

    vector<int> arr;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        arr.push_back(x);
    }

    int k; cin >> k;

    int low = 0, high = n - 1;
    vector<int> res;

    BinSearch(arr, res, low, high, k);

    if(res.empty() || res.back() != k) 
        cout << "Not Found";
    else{
        for(int i = 0; i < res.size(); ++i){
            if(i != 0) cout << " ";
            cout << res[i];
        }
    }

    cout << endl;
    return 0;
}