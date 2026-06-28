#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream fin("in.txt");
    int n; fin >> n;

    vector<pair<int, int>> soldiers(n);
    for(int i = 0; i < n; ++i) {
        fin >> soldiers[i].first 
            >> soldiers[i].second;
    }

    sort(soldiers.begin(), soldiers.end(),
        [](const pair<int, int>& a, const pair<int, int>& b) {
            if(a.second == b.second) return a.first < b.first;
            return a.second < b.second;
        });

    int mid = soldiers[n / 2].second;
    int y_count = 0;
    for(int i = 0; i < n; ++i)
        y_count += abs(soldiers[i].second - mid);

    sort(soldiers.begin(), soldiers.end(),
        [](const pair<int, int>& a, const pair<int, int>& b) {
            if(a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });
    
    for(int i = 0; i < n; ++i)
        soldiers[i].first -= i;

    sort(soldiers.begin(), soldiers.end(),
        [](const pair<int, int>& a, const pair<int, int>& b) {
            if(a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });
    
    mid = soldiers[n / 2].first;
    int x_count = 0;
    for(int i = 0; i < n; ++i)
        x_count += abs(soldiers[i].first - mid);
    
    cout << x_count + y_count << endl;
    return 0;
}