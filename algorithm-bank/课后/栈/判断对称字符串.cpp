#include <iostream>
#include <string>
#include <sstream>
using namespace std;

char sta[100005];
int top = -1;

int main(){
    string line;
    getline(cin, line);
    istringstream iss(line);

    char c;
    while(iss >> c && c != '@'){
        sta[++top] = c;
    }

    while(iss >> c && top != -1){
        if(sta[top] != c) break;
        top--;
    }

    if(top != -1 || iss >> c) cout << 0 << endl;
    else cout << 1 << endl;

    return 0;
}
