#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> s;

        for (int i = 0; i < nums.size(); i++) {
            s.push_back(to_string(nums[i]));
        }

        sort(s.begin(), s.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });

        if (s.size() > 0 && s[0] == "0") {
            return "0";
        }

        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            ans += s[i];
        }

        return ans;
    }
};

int main() {
    ifstream fin("in.txt");

    if (!fin.is_open()) {
        return 0;
    }

    string line;
    getline(fin, line);

    vector<int> nums;
    int num = 0;
    bool hasNum = false;

    for (int i = 0; i < line.length(); i++) {
        if (line[i] >= '0' && line[i] <= '9') {
            num = num * 10 + (line[i] - '0');
            hasNum = true;
        } else if (line[i] == ',') {
            if (hasNum) {
                nums.push_back(num);
                num = 0;
                hasNum = false;
            }
        }
    }

    if (hasNum) {
        nums.push_back(num);
    }

    Solution sol;
    cout << sol.largestNumber(nums) << endl;

    fin.close();

    return 0;
}