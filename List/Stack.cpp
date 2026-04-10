#include <iostream>
using namespace std;

const int MaxSize = 105;

template <typename T>
class SqStack{
private:
    T* data;
    int top;  //栈顶指针（int型，表示数组下标）

public:
    SqStack(){
        data = new T[MaxSize];
        top = -1;
    }

    ~SqStack(){
        delete [] data;
    }

    bool empty(){
        return top == -1;
    }

    bool push(T e){
        if(top == MaxSize) return false;
        top++;
        data[top] = e;
        return true;
    }

    bool pop(T& e){
        if(top == -1) return false;
        top--;
        e = data[top];
        return true;
    }

    bool gettop(T& e){
        if(empty()) return false;
        e = data[top];
        return true;
    }
};

template <typename T>
struct LinkNode{
    T data;
    LinkNode* next;
    LinkNode() : next(nullptr){}
    LinkNode(T d) : data(d), next(nullptr){}
};

template <typename T>
class LinkStack{
public:
    LinkNode<T>* head;

    LinkStack(){
        head = new LinkNode<T>();
    }

    ~LinkStack(){
        LinkNode<T>* pre = head, *p = pre -> next;
        while(p != nullptr){
            delete pre;
            pre = p, p = p -> next;
        }
        delete pre; //别忘了最后一个
    }

    // 禁用拷贝构造函数
    LinkStack(const LinkStack& s) = delete;

    // 禁用赋值操作符
    LinkStack& operator=(const LinkStack& s) = delete;

    bool empty(){
        return(head -> next == nullptr);
    }

    bool push(T e){
        LinkNode<T>* p = new LinkNode<T>(e);
        p -> next = head -> next;
        head -> next = p;
        return true;
    }

    bool pop(T& e){
        LinkNode<T>* p;
        if(empty()) return false;
        p = head -> next;
        e = p -> data;
        head -> next = p -> next;
        delete p;
        return true;
    }

    bool gettop(T& e){
        LinkNode<T>* p;
        if(empty()) return false;
        p = head -> next;
        e = p -> data;
        return true;
    }
};