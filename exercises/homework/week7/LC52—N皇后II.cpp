#include <iostream>
#include <vector>
#include <fstream> // 必须包含这个头文件来操作文件

using namespace std;

// 题目要求的类结构
class Solution {
private:
    int total;
    vector<bool> cols;
    vector<bool> main_diag;
    vector<bool> anti_diag;

    void backtrack(int n, int row) {
        if (row == n) {
            total++;
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (!cols[i] && !main_diag[row - i + n] && !anti_diag[row + i]) {
                cols[i] = true;
                main_diag[row - i + n] = true;
                anti_diag[row + i] = true;

                backtrack(n, row + 1);

                cols[i] = false;
                main_diag[row - i + n] = false;
                anti_diag[row + i] = false;
            }
        }
    }

public:
    int totalNQueens(int n) {
        // 每处理一个新的 n，必须把总数清零，并重置防碰撞数组！
        total = 0;
        cols.assign(n, false);
        main_diag.assign(2 * n, false);
        anti_diag.assign(2 * n, false);
        
        backtrack(n, 0);
        
        return total;
    }
};

int main() {
    // 1. 严格按照题目说明，打开 in.txt 文件
    ifstream in("in.txt");
    
    // 2. 声明准备接收数据的变量和类
    int n;
    Solution sol;
    
    // 3. 核心：你猜得完全正确！必须用 while 循环一直读，直到文件结束
    while (in >> n) {
        // 调用接口计算，并直接将结果输出到屏幕（标准输出）
        cout << sol.totalNQueens(n) << endl;
    }
    
    // 养成好习惯，关闭文件
    in.close();
    
    return 0;
}