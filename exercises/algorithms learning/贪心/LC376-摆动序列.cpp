#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        stack<int> st;
        int dir = 0;
        for(int x : nums) {
            if(st.empty()) {
                st.push(x);
                continue;
            }

            if(x == st.top()) continue;

            int cur = (x > st.top()) ? 1 : -1;

            if(dir == 0 || cur != dir) {
                st.push(x);
                dir = cur;
            }
            else {
                st.pop();
                st.push(x);
            }
        }

        return st.size();
    }
};