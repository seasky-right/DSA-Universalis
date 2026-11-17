#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        for(int& x : nums) {
            if(x < 0 && k > 0) {
                x = -x;
                k--;
            } else break;
        }

        if(k % 2 != 0)
            *min_element(nums.begin(), nums.end()) *= -1;

        int ans = 0;
        for(int x : nums)
            ans += x;

        return ans;
    }
};