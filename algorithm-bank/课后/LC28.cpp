#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream infile("in.txt");
    string s1, s2, ass;
    while (getline(infile, s1) && getline(infile, s2)){

        while (!s1.empty() && s1.back() < 32) s1.pop_back();
        while (!s2.empty() && s2.back() < 32) s2.pop_back();

        int i = 0, j = 0;
        while(i < s1.length() && j < s2.length()){
            if(s1[i] == s2[j]) {
                i++; j++;
            }
            else{
                i = i - j + 1;
                j = 0;
            }
        }

        if(j == s2.length()) cout << i - j << endl;
        else cout << -1 << endl;
    }

    return 0;
}