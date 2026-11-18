#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            return intersect(nums2, nums1);

        unordered_map<int, int> cnt;
        for(int x : nums1) cnt[x]++;

        vector<int> ans;
        for(int x : nums2) {
            if(cnt[x] > 0) {
                ans.push_back(x);
                cnt[x]--;
            }
        }

        return ans;
    }
};

/*有序数组二路归并
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> ins;
        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] > nums2[j]) j++;
            else if(nums1[i] < nums2[j]) i++;
            else {
                ins.push_back(nums1[i]);
                i++; j++;
            }
        }

        return ins;
    }
};
*/
