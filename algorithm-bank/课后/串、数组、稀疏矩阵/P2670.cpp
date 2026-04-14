#include <iostream>
using namespace std;

char field[105][105];

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> field[i][j];
        }
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(field[i][j] == '*'){ cout << '*'; }
            else{
                int count = 0;
                for(int dx = -1; dx <= 1; ++dx){
                    for(int dy = -1; dy <= 1; ++dy){
                        if(dx == 0 && dy == 0) continue;
                        else if(field[i + dx][j + dy] == '*') count++;
                    }
                }
                cout << count;
            }
        }
        cout << endl;
    }

    return 0;
}