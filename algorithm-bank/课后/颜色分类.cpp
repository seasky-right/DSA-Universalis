#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int colors[3] = {0};

    for(int i = 0; i < n; ++i){
        int c;
        cin >> c;
        colors[c]++;
    }

    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < colors[i]; ++j){
            cout << i << " ";
        }
    }

    return 0;
}