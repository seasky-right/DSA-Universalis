#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void BinSearch(const vector<int>& arr, vector<int>& res, int low, int high, int key) {
    if (low > high) return;
    int mid = low + (high - low) / 2;
    res.push_back(arr[mid]);
    if (arr[mid] == key) return;
    else if (arr[mid] < key)
        BinSearch(arr, res, mid + 1, high, key);
    else
        BinSearch(arr, res, low, mid - 1, key);
}

int main() {
    ifstream fin("in.txt");
    ofstream fout("out.txt");

    string k_line, data_line;
    while (getline(fin, k_line)) { // 连关键字也用 getline 读整行，彻底消灭换行符残留
        if (k_line.empty()) continue;
        
        // 1. 用首层流解析出关键字 k
        stringstream k_ss(k_line);
        int k;
        k_ss >> k;
        
        // 2. 读取第二行
        if (!getline(fin, data_line)) break;
        
        // 3. 用嵌套流一气呵成地解包整个数组（自动处理负数、任意多空格）
        stringstream data_ss(data_line);
        vector<int> arr;
        int num;
        while (data_ss >> num) {
            arr.push_back(num);
        }

        vector<int> res;
        if (!arr.empty()) {
            BinSearch(arr, res, 0, arr.size() - 1, k);
        }

        if (res.empty() || res.back() != k)
            fout << "False" << endl;
        else
            fout << "True" << endl;

        for (size_t i = 0; i < res.size(); ++i) {
            if (i != 0) fout << " ";
            fout << res[i];
        }
        fout << endl;
    }
    return 0;
}