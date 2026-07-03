// DP
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string word1, word2;
    cin >> word1 >> word2;
    int n = word1.length(), m = word2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // 初始化：word1 的前 i 个字符变成空串，需要删除 i 次
    for(int i = 0; i <= n; ++i)
        dp[i][0] = i;

    // 初始化：空串变成 word2 的前 j 个字符，需要插入 j 次
    for(int j = 0; j <= m; ++j)
        dp[0][j] = j;

    // 填表
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(word1[i - 1] == word2[j - 1]) {
                // 最后一个字符相同，不需要额外操作
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                int del = dp[i - 1][j] + 1;      // 删除
                int ins = dp[i][j - 1] + 1;      // 插入
                int rep = dp[i - 1][j - 1] + 1;  // 替换

                dp[i][j] = min({del, ins, rep});
            }
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}

/*
**DP**: 以子问题所需变量为维度，构建子问题结果表。
本质类似递归，都是在定义子问题，并假设子问题答案可靠；
递归是需要时向下求，DP 是提前按顺序把子问题填好。
*/