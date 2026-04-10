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
        Node* s = new Node(c);
        if(top != nullptr && c == '#'){
            Node* temp = top;
            top = top -> next;
            delete temp;
        }else if(c != '#'){
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