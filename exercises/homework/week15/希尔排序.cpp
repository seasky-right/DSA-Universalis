#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void shellSort(vector<int>& arr) {
    int n = arr.size();
    int d = n / 2;

    while(d > 0) {
        for(int i = d; i < n; ++i) {
            int tmp = arr[i];
            int j = i - d;
            while(j >= 0 && arr[j] > tmp) {
                arr[j + d] = arr[j];
                j -= d;
            }
            arr[j + d] = tmp;
        }
        d /= 2;
    }
}

int main() {
    ifstream fin("in.txt");
    ofstream fout("out.txt");

    vector<int> arr; int n;
    while(fin >> n) {
        arr.push_back(n);
    }

    shellSort(arr);

    bool isFirst = true;
    for(size_t i = 0; i < arr.size(); ++i) {
        if(!isFirst) fout << " ";
        isFirst = false;
        fout << arr[i];
    }

    cout << endl;
    return 0;
}