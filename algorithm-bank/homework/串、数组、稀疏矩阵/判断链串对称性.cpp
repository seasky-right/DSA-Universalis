#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node() : data(' '), next(nullptr) {}
    Node(char c) : data(c), next(nullptr) {}
};

int main() {
    Node* hh = new Node(), *r = hh;
    string line;
    getline(cin, line);
    int isAt = -1;
    for(size_t i = 0; i < line.size(); ++i){
        if(line[i] == '@') isAt = (int)i;
        r -> next = new Node(line[i]);
        r = r -> next;
    }

    if(isAt == -1 || line.size() != 2 * isAt + 1){
        cout << "false" << endl;
        return 0;
    }

    Node* p1 = hh -> next, *p2 = hh -> next;
    for(int i = 0; i <= isAt; ++i) p2 = p2 -> next;
    
    while(p2 != nullptr){
        if(p1 -> data != p2 -> data){
            cout << "false" << endl;
            return 0;
        }
        p1 = p1 -> next;
        p2 = p2 -> next;
    }

    cout << "true" << endl;
    return 0;
}