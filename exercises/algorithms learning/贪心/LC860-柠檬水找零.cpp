#include <vector>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiv = 0, ten = 0;
        int n = bills.size();
        for(int i = 0; i < n; ++i) {
            if(bills[i] == 5) fiv++;
            else if(bills[i] == 10) {
                if(fiv != 0) {
                    fiv--; ten++;
                }
                else return false;
            }
            else {
                if(ten != 0 && fiv != 0) {
                    fiv--; ten--;
                }
                else if(fiv >= 3)
                    fiv -= 3;
                else return false;
            }
        } 
        return true;
    }
};