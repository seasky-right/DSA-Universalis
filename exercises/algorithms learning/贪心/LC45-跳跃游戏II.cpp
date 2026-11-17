// 沿着原数组跑来覆盖所有可能路线
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int steps = 0, end = 0, far = 0;

        for(int i = 0; i < n - 1; ++i) {
            far = max(far, i + nums[i]);

            if(i == end) {
                steps++;
                end = far;
            }
        }

        return steps;
    }
};

/* DP暴力枚举
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> times(n + 1, INT_MAX);
        times[0] = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 1; j <= nums[i] && i + j < n; ++j)
                times[i + j] = min(times[i] + 1, times[i + j]);
        }

        return times[n - 1];
    }
};*/