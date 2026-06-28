#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream fin("in.txt");
    int n; fin >> n;

    vector<pair<int, int>> sticks(n);
    for(int i = 0; i < n; ++i)
        fin >> sticks[i].first >> sticks[i].second;

    sort(sticks.begin(), sticks.end(), 
        [](const pair<int, int>&a, const pair<int, int>&b) {
            if(a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });

    int minutes = 0, processed = 0;
    vector<bool> visited(n, false);
    while(processed < n) {
        int cur_w = -1;

        for(int i = 0; i < n; ++i) {
            if(!visited[i]) {
                visited[i] = true;
                cur_w = sticks[i].second;
                processed++;
                minutes++;
                break;
            }
        }

        for(int i = 0; i < n; ++i) {
            if(!visited[i] && sticks[i].second >= cur_w) {
                visited[i] = true;
                cur_w = sticks[i].second;
                processed++;
            }
        }
    }

    cout << minutes << endl;
    return 0;
}