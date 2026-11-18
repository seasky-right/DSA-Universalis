#include <vector>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](auto& a, auto& b){
            return a[1] < b[1];
        });

        int ans = 1;
        int pos = points[0][1];

        for(int i = 1; i < points.size(); ++i) {
            if(points[i][0] > pos) {
                ans++;
                pos = points[i][1];
            }
        }

        return ans;
    }
};