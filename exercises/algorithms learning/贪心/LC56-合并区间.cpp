#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int l = intervals[0][0], r = intervals[0][1];
        int n = intervals.size();
        vector<vector<int>> ans;
        for(int i = 1; i < n; ++i) {
            int x = intervals[i][0];
            if(x > r) {
                ans.push_back({l, r});
                l = x;
            }
            r = max(r, intervals[i][1]);
        }
        ans.push_back({l, r});

        return ans;
    }
};