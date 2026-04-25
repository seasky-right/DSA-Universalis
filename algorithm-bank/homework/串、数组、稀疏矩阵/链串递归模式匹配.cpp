#include <iostream>

using namespace std;

struct Node{
    char data;
    Node* next;
    Node() : data(), next(nullptr) {}
    Node(char c) : data(c), next(nullptr) {}
};

class Mystring{
public:
    Node* head, *r;
    int length;

    Mystring(){
        head = new Node(), r = head;
        length = 0;
    }

    void push(char c){
        Node* s = new Node(c);
        r -> next = s;
        r = s;
        length++;
    }

    bool empty() const{
        return length == 0;
    }
};

bool isMatch(Node* sp, Node* tp){
    if(!tp) return true;
    if(!sp) return false;
    if(sp -> data == tp -> data)
        return isMatch(sp -> next, tp -> next);
    return false;
}

int findMatch(Node* sp, Node* tp){
    if(!sp) return 0;
    if(isMatch(sp, tp))
        return 1 + findMatch(sp -> next, tp);
    else
        return findMatch(sp -> next, tp);
}

int PatternMatch(const Mystring& s, const Mystring& t){
    if(s.empty() || t.empty()) return 0;
    return findMatch(s.head -> next, t.head -> next);
}

int main(){
    string str1, str2;
    cin >> str1 >> str2;
    Mystring s, t;
    for(char c : str1) s.push(c);
    for(char c : str2) t.push(c);
    cout << PatternMatch(s, t) << endl;
    return 0;
}