#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    getline(cin, str);

    for (size_t i = 0; i < str.length(); i++){
        char ch = str[i];
        if(ch == 'a') str[i] = 'z';
        else if (ch == 'A') str[i] = 'Z';
        else if ((ch > 'a' && ch <= 'z') || (ch > 'A' && ch <= 'Z')) str[i] = ch - 1;
    }
    cout << str << endl;
    return 0;
}