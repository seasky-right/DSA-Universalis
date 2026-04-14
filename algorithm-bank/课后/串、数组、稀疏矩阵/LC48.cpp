#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
    ifstream infile("in.txt");
    if(!infile) return 0;

    int n, x; 
    while(infile >> n){
        vector<vector<int>> matrix(n, vector<int>(n));

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                infile >> x;
                matrix[i][j] = x;
            }
        }

        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n / 2; ++j){
                swap(matrix[i][j], matrix[i][n - 1 - j]);
            }
        }

        for(int i = 0; i < n; ++i){
            bool isFirst = true;
            for(int j = 0; j < n; ++j){
                if(!isFirst) cout << " ";
                cout << matrix[i][j];
                isFirst = false;
            }
            cout << "\n";
        }
    }
    
    return 0;
}