#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void quickSort(vector<int>& arr, int low, int high) {
    if(low >= high) return;

    int pivot = arr[low];
    int i = low, j = high;

    while(i < j) {
        // 谁先动取决于坑在哪
        while(i < j && arr[j] >= pivot)
            j--;
        if(i < j) arr[i++] = arr[j];

        while(i < j && arr[i] <= pivot) 
            i++;
        if(i < j) arr[j--] = arr[i];
    }
    arr[i] = pivot;

    quickSort(arr, low, i - 1);
    quickSort(arr, i + 1, high);
}

int main() {
    ifstream fin("in.txt");
    ofstream fout("out.txt");

    vector<int> arr; int n;
    while(fin >> n) {
        arr.push_back(n);
    }

    int l = 0, h = arr.size() - 1;
    quickSort(arr, l, h);

    bool isFirst = true;
    for(size_t i = 0; i < arr.size(); ++i) {
        if(!isFirst) fout << " ";
        isFirst = false;
        fout << arr[i];
    }

    cout << endl;
    return 0;
}