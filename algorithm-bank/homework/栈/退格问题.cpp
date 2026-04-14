//顺序栈实现
#include <iostream>
using namespace std;

const int MaxSize = 1000005;
char stk[MaxSize];
int tt = 0;

int main(){
    string s; cin >> s;
    for(char c : s){
        if(c == '#'){
            if(tt > 0)tt--;
        }
        else{
            stk[--tt] = c;
        }
    }

    for(int i = 1; i <= tt; ++i){
        cout << stk[i];
    }

    cout << endl;
    return 0;
}

/*链栈实现
#include <iostream>
#include <string>
using namespace std;

struct Node{
    char data;
    Node* next;
    Node() : data(), next(nullptr) {}
    Node(char c) : data(c), next(nullptr) {}
};

int main(){
    string line;
    getline(cin, line);

    Node* top = nullptr;
    for(char c : line){
        if(c == '#'){
            if(top != nullptr){
                Node* temp = top;
                top = top -> next;
                delete temp;
            }
        }else if(c != '#'){
            Node* s = new Node(c);
            s -> next = top;
            top = s;
        }
    }

    Node* temptop = nullptr; 
    while(top != nullptr){
        Node* temp = top;
        top = top -> next;
        temp -> next = temptop;
        temptop = temp;
    }

    Node* p = temptop;
    while(p != nullptr){
        cout << p -> data;
        p = p -> next;
    }

    cout << endl;
    return 0;
}*/