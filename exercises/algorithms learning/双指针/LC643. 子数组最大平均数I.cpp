#include <vector>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l = 0, r = k;

        int maxSum = 0;
        for(int i = 0; i < k; ++i) maxSum += nums[i];
        int sum = maxSum;
        while(r < nums.size()) {
            sum = sum + nums[r] - nums[l];
            maxSum = max(maxSum, sum);
            r++; l++;
        }

        return double(maxSum) / k;
    }
};