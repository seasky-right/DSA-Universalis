#include <iostream>
#include <stack>
using namespace std;

bool isDigit(int n){
    return (n >= '0' && n <= '9');
}

int getPrior(char c){
    if(c == '+' || c == '-') return 1;
    else if(c == '*' || c == '/') return 2;
    else return 0;
}

int main(){
    string str;
    getline(cin, str);
    stack<char> op;
    bool isFirst = true;
    for(size_t i = 0; i < str.size(); ){
        char c = str[i];
        if(isDigit(c)){
            string num;
            while(isDigit(str[i])){
                num += str[i++];
            }
            if(!isFirst) cout << " ";
            cout << num;
            isFirst = false;
            continue;
        }else{
            if(op.empty()){
                op.push(c);
                i++;
                continue;
            }
            else if(c == ')'){
                while(!op.empty() && op.top() != '('){
                    cout << " " << op.top();
                    op.pop();
                }
                op.pop();
                i++;
                continue;
            }
            else if(c == '(') {}
            else{
                while(!op.empty() && op.top() != '(' && getPrior(c) <= getPrior(op.top())){
                    cout << " " << op.top();
                    op.pop();
                }
            }
            op.push(c);
        }
        ++i;
    }

    while(!op.empty()){
        cout << " " << op.top();
        op.pop();
    }

    return 0;
}