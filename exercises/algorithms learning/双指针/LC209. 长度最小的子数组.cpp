// 滑动窗口
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0;
        int sum = 0, ans = INT_MAX;

        while(r < nums.size()) {
            sum += nums[r];

            while(sum >= target) {
                ans = min(ans, r - l + 1);
                sum -= nums[l];
                l++;
            }

            r++;
        }

        return ans == INT_MAX ? 0 : ans;
    }
};

/*前缀和+二分查找
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n + 1, 0);

        for(int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + nums[i];
        }

        int ans = INT_MAX;
        for(int i = 0; i < n; ++i) {
            auto it = lower_bound(
                pre.begin() + i + 1,
                pre.end(),
                pre[i] + target
            );

            if(it != pre.end()) {
                int j = it - pre.begin();
                ans = min(ans, j - 1);
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};
*/