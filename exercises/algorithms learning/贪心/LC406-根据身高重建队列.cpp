#include <vector>
#include <list>

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b){
                if(a[0] != b[0]) return a[0] > b[0];
                else return a[1] < b[1];
            });

        list<vector<int>> ans;
        for(vector<int>& p : people) {
            auto it = next(ans.begin(), p[1]);
            ans.insert(it, p);
        }
            
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};