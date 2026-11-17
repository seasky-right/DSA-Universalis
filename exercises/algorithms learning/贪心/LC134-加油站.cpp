#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sum = 0, minSum = 0;
        int start = 0;

        for(int i = 0; i < n; ++i) {
            sum += gas[i] - cost[i];

            if(sum < minSum) {
                minSum = sum;
                start = i + 1;
            }
        }

        if(sum < 0) return -1;
        return start;
    }
};