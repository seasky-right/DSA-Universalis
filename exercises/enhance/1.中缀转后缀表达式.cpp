#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
using namespace std;

string precedence(char op) {
    if (op == '+' || op == '-') return "1";
    if (op == '*' || op == '/') return "2";
    return "0";
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

string infixToPostfix(const string& infix) {
    stack<char> s;
    stringstream ss;
    for (char c : infix) {
        if (isdigit(c)) {
            ss << c << " ";
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                ss << s.top() << " ";
                s.pop();
            }
            s.pop(); // Remove the '('
        } else if (isOperator(c)) {
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                ss << s.top() << " ";
                s.pop();
            }
            s.push(c);
        }
    }
    while (!s.empty()) {
        ss << s.top() << " ";
        s.pop();
    }
    return ss.str();
}

int main() {
    string infix;
    cin >> infix;
    cout << infixToPostfix(infix) << endl;
    return 0;
}
