#include <vector>

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        vector<int> digits;
        if(n == 0) return 0;
        while(n > 0) {
            int x = n % 10; n /= 10;
            digits.push_back(x);
        }

        int pre = 10, mark = 0;;
        for(int i = 0; i < digits.size(); ++i) {
            if(digits[i] > pre) {
                digits[i]--;
                mark = i;
            }
        
            pre = digits[i];
        }

        for(int j = 0; j < mark; ++j) {
            digits[j] = 9;
        }

        reverse(digits.begin(), digits.end());
        int ans = 0;
        for(int i = 0; i < digits.size(); ++i) {
            ans = ans * 10 + digits[i];
        }
        return ans;
    }
};