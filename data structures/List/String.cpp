#include <iostream>

using namespace std;
const int MaxSize = 100;
class SqString{
public:
    char* data;
    int length;

    SqString& SubStr(int i, int j){
        static SqString s;
        if(i < 0 || i >= length ||
        j < 0 || i + j > length) 
            return s;
        for(int k = i; k < i + j; ++k)
            s.data[k - i] = data[k];
        s.length = j;
        return s;
    }
};

struct Node {
    char data;
    Node* next;
    Node() : data(' '), next(nullptr) {}
    Node(char c) : data(c), next(nullptr) {}
};

class LinkString{
public:
    Node* head;
    int length;

    LinkString& InsStr(int i, LinkString& t){
        static LinkString s;
        if(i < 0 || i > length) return s;
        Node* p = head -> next, *p1 = t.head -> next;
        Node* r = s.head;
        for(int k = 0; k < i; ++k){
            Node* q = new Node(p -> data);
            r -> next = q; r = q;
            p = p -> next;
        }

        while(p1 != nullptr){
            Node* q = new Node(p1 -> data);
            r -> next = q; r = q;
            p1 = p1 -> next;
        }

        while(p != nullptr){
            Node* q = new Node(p -> data);
            r -> next = q; r = q;
            p = p -> next;
        }

        s.length = length + t.length;
        r -> next = nullptr;
        return s;
    }
};

int BF(string s, string t){
    int i = 0, j = 0;
    while(i < s.length() && j < t.length()){
        if(s[i] == t[j]){
            i++;
            j++;
        }else{
            i = i - j + 1;
            j = 0;
        }
    }
    if(j >= t.length()) return i - t.length();
    else return -1;
}

void GetNext(string t, int* next){
    int j = 0, k = -1;
    next[0] = -1;
    while(j < t.length() - 1){
        if(k == -1 || t[j] == t[k]){
            j++; k++;
            next[j] = k;
        }else{
            k = next[k]; //查找更短的相同前后缀，相当于在目前的相等块内部重新查找
        }
    }
}

int KMP(string s, string t){
    int n = s.length(), m = t.length();
    int* next = new int[m];
    GetNext(t, next);
    int i = 0, j = 0;
    while(i < n && j < m){
        if(j == -1 || s[i] == t[j]){
            i++; j++;
        }else j = next[j];
    }
    if(j >= m) return i - m;
    else return -1;
}