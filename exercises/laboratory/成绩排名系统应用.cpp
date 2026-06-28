#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int c = 0;
void heapify(vector<int>& arr, int n, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if(l < n){
        c++;
        if(arr[smallest] > arr[l])
            smallest = l;
    }

    if(r < n){
        c++;
        if(arr[smallest] > arr[r])
            smallest = r;
    }

    if(smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}


void printArr(vector<int>& arr) {
    bool first = true;
    for(size_t i = 0; i < arr.size(); ++i) {
        if(!first) cout << " ";
        cout << arr[i];
        first = false;
    }
    cout << endl;
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    for(int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }
    printArr(arr);

    for(int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
    printArr(arr);
}

int main() {
    int n; cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        arr.push_back(x);
    }

    heapSort(arr);

    cout << c << endl;
    return 0;
}