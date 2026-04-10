#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream infile("in.txt");
    string s1, s2;

    while(infile >> s1 >> s2){
        string s = s1 + "#" + s2;

        int j = 0, k = -1;
        int* next = new int[s.length() + 1];
        next[0] = -1;
        while(j < s.length()){
            if(k == -1 || s[j] == s[k]){
                j++; k++;
                next[j] = k;
            }
            else k = next[k];
        }

        if(k < 1) cout << 0 << endl;
        else cout << s1.substr(0, k) << " " << k << endl;

        delete[] next;
    }
    return 0;
}