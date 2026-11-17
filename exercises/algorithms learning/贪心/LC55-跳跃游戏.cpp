#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int far = 0;
        for(int i = 0; i < n; ++i) {
            if(i > far) return false;
            far = max(far, i + nums[i]);
            if(far >= n - 1) return true;
        }

        return true;
    }
};