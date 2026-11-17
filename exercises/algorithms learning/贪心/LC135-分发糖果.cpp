// 左右分别计算，再合并
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);

        for(int l = 1; l < n; ++l) {
            if(ratings[l - 1] < ratings[l])
                candies[l] = candies[l - 1] + 1;
        }
        for(int r = n - 2; r >= 0; --r) {
            if(ratings[r + 1] < ratings[r])
                candies[r] = max(candies[r], candies[r + 1] + 1);
        }

        int sum = 0;
        for(int x : candies)
            sum += x;

        return sum;
    }
};