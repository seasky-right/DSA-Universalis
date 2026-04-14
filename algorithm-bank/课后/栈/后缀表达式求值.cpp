#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

bool isDigit(char c){
    return (c <= '9' && c >= '0');
}

int main(){
    string line;
    getline(cin, line);
    istringstream iss(line);
    stack<int> num;
    string item;

    while(iss >> item){
        if(isDigit(item[0])){
            num.push(stoi(item));
        }
        else{
            int a = num.top(); num.pop();
            int b = num.top(); num.pop();
            if(item == "+") num.push(b + a);
            else if(item == "-") num.push(b - a);
            else if(item == "*") num.push(b * a);
            else if(item == "/") num.push(b / a);
        }
    }

    cout << num.top();
    return 0;
}