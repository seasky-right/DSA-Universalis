#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

vector<vector<int>> grid;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int maxArea() {
    queue<pair<int, int>> qu;
    int max_area = 0, cur_area = 0;
    for(size_t i = 0; i < grid.size(); ++i) {
        for(size_t j = 0; j < grid[i].size(); ++j) {
            if(grid[i][j] == 1) {
                qu.push({i, j});
                cur_area++;
                grid[i][j] = 0;
                while(!qu.empty()){
                    pair<int, int> curr = qu.front(); qu.pop();
                    for(int n = 0; n < 4; ++n) {
                        int x = curr.first + dx[n];
                        int y = curr.second + dy[n];
                        if(x >= 0 && x < grid.size() && 
                            y >= 0 && y < grid[x].size() && 
                            grid[x][y] == 1) {
                            qu.push({x, y});
                            cur_area++;
                            grid[x][y] = 0;
                        }
                    }
                }
                max_area = max(max_area, cur_area);
                cur_area = 0;
            }
        }
    }
    return max_area;
}

int main() {
    ifstream fin("in.txt");
    string line;
    while(getline(fin, line)) {
        istringstream iss(line);
        int x;
        vector<int> row;
        while(iss >> x)
            row.push_back(x);
        
        if(!row.empty()) grid.push_back(row);
    }

    cout << maxArea() << endl;
    return 0;
}