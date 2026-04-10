#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isDigit(char c){
    return(c >= '0' && c <= '9');
}

int getPriority(char op){
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    if(op == '(') return 0;
    return -1;
}

int main(){
    string str;
    getline(cin, str);
    stack<char> s;
    bool isFirst = true;
    for(size_t i = 0; i < str.length(); ){
        if(isDigit(str[i])){
            string num;
            while(i < str.length() && isDigit(str[i])){
                num += str[i++];
            }
            if(!isFirst) cout << " ";
            cout << num;
            isFirst = false;
        }else{
            if(str[i] == '(') s.push(str[i]);
            else if(str[i] == ')'){
                while(!s.empty() && s.top() != '('){
                    cout << " " << s.top();
                    s.pop();
                }
                s.pop();
            }else{
                while(!s.empty() && s.top() != '(' &&
                getPriority(str[i]) <= getPriority(s.top())){
                    cout << " " << s.top();
                    s.pop();
                }
                s.push(str[i]);
            }
            ++i;
        }
    }
    while(!s.empty()){
        cout << " " << s.top();
        s.pop();
    }
    return 0;
}