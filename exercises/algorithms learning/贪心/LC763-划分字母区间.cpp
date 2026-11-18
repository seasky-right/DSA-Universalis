#include <vector>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last[26] = {};

        for(int i = 0; i < s.size(); ++i)
            last[s[i] - 'a'] = i;
        
            vector<int> ans;
            int l = 0, r = 0;

            for(int i = 0; i < s.size(); ++i) {
                r = max(r, last[s[i] - 'a']);

                if(i == r) {
                    ans.push_back(r - l + 1);
                    l = i + 1;
                }
            }

            return ans;
    }
};