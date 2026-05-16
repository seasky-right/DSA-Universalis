#include <iostream>
#include <string>

using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* CreateList(string s){
    Node* head = new Node;
    head -> next = nullptr;
    Node* r = head;

    s += ' ';

    int num = 0;
    bool isNum = false;
    bool isNeg = false;
    for(char c : s){
        if(c >= '0' && c <= '9'){
            isNum = true;
            num = num * 10 + (c - '0');
        }else if(c == '-'){
            isNeg = true;
        }else{
            if(isNum){
                if(isNeg) num = -num;
                Node* n = new Node;
                n -> data = num;
                r -> next = n;
                r = n;

                num = 0;
                isNum = false;
                isNeg = false;
            }
        }
    }

    return head;
}

int main(){
    string s1, s2;

    getline(cin, s1);
    Node* head1 = CreateList(s1);
    getline(cin, s2);
    Node* head2 = CreateList(s2);

    Node* reshead = new Node;
    reshead -> next = nullptr;

    Node* p1 = head1 -> next, *p2 = head2 -> next;

    while(p1 != nullptr && p2 != nullptr){
        if(p1 -> data < p2 -> data) p1 = p1 -> next;
        else if(p1 -> data > p2 -> data) p2 = p2 -> next;
        else{
            Node* s = new Node;
            s -> data = p1 -> data;
            s -> next = reshead -> next;
            reshead -> next = s;

            p1 = p1 -> next;
            p2 = p2 -> next;
        }
    }

    if(reshead -> next == nullptr) cout << "error" << endl;
    else{
        Node* p = reshead -> next;
        bool isFirst = true;
        while(p != nullptr){
            if(!isFirst) cout << " ";
            isFirst = false;
            cout << p -> data;
            p = p -> next;
        }
        cout << endl;
    }

    return 0;
}