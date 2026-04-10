#include <iostream>
#include <stack>

using namespace std;
int main(){
    string str;
    cin >> str;
    stack<char> p;
    for(char c : str){
        if(c == '(' || c == '{' || c == '['){
            p.push(c);
            continue;
        }
        else{
            if(p.empty()){
                p.push(c);
                break;
            }
            if((p.top() == '[' && c == ']')
            ||(p.top() == '{' && c == '}')
            ||(p.top() == '(' && c == ')')){
                p.pop();
            }
            else{
                p.push(c);
            }
        }
    }
    if(p.empty()) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}