#include <iostream>
using namespace std;

void getNext(string s, int* next){
    int j = 0, k = -1;
    next[0] = -1;
    while(j < s.length()){
        if(k == -1 || s[j] == s[k]){
            j++; k++;
            next[j] = k;
        }
        else{
            k = next[k];
        }
    }
}

int main(){
    string s, t;
    getline(cin, t);
    getline(cin, s);

    int* next = new int[t.length() + 1];
    getNext(t, next);

    int i = 0, j = 0, count = 0;
    while(i < s.length()){
        if(j == -1 || s[i] == t[j]){
            i++; j++;
        }else j = next[j];

        if(j == t.length()){
            count++;
            j = next[j];
        }
    }

    cout << count << endl;
    delete[] next;

    return 0;
}