#include <iostream>

using namespace std;

int getNo(const string& s, char x, int index){
    if(s.empty() || index < 0) return -1;
    if(s[index] == x) return index;
    else return getNo(s, x, index - 1);
}

int main(){
    string s; char x;
    getline(cin, s);
    cin >> x;

    cout << getNo(s, x, s.length() - 1) << endl;
    return 0;
}