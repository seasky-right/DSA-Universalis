#include <vector>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){
            return a[1] < b[1];
        });

        int ans = 0;
        int pos = intervals[0][1];

        for(int i = 1; i < intervals.size(); ++i) {
            if(intervals[i][0] < pos)
                ans++;
            else pos = intervals[i][1];
        }

        return ans;
    }
};