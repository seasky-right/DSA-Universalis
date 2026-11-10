#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isNum(char c) { return c >= '0' && c <= '9'; }

string decode(const string &s, size_t &i) {
    string res = "";

    while (i < s.size() && s[i] != ']') {

        if (isNum(s[i])) {
            int num = 0;

            // 1. 读取完整数字
            while(i < s.size() && isNum(s[i])){ num = num * 10 + (s[i++] - '0'); }
            // 2. 跳过 [
            if(s[i] == '[') i++;
            // 3. 调用 decode() 处理内部字符串
            string ans = decode(s, i);
            // 4. 跳过 ]
            if(s[i] == ']') i++;
            // 5. 将内部结果重复 num 次，拼接到 res
            for(int j = 0; j < num; ++j) { res += ans; }
        }
        else {
            res += s[i];
            i++;
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    size_t i = 0;
    string res = decode(s, i);

    cout << res << '\n';
    return 0;
}