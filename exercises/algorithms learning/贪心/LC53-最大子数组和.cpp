#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int ans = INT_MIN;
        int minPre = 0;
        for(int x : nums) {
            sum += x;
            ans = max(ans, sum - minPre);
            if(sum < minPre) minPre = sum;
        }
        return ans;
    }
};