#include <iostream>
using namespace std;

const int MaxSize = 105;
template <typename T>
class CSeQueue{
public:
    T* data;
    int front, rear;

    CSeQueue(){
        data = new T[MaxSize];
        front = rear = 0;
    }

    ~CSeQueue(){
        delete [] data;
    }

    bool empty(){
        return (front == rear);
    }

    bool push(T e){
        if((rear+1) % MaxSize == front) return false;
        rear = (rear+1) % MaxSize;
        data[rear] = e;
        return true;
    }

    bool pop(T& e){
        if(empty()) return false;
        front = (front+1) % MaxSize;
        e = data[front];
        return true;
    }

    bool gethead(T& e){
        if(empty()) return false;
        int head = (front+1) % MaxSize;
        e = data[head];
        return true;
    }
};

template <typename T>
struct LinkNode{
    T data;
    LinkNode* next;
    LinkNode() : next(nullptr) {}
    LinkNode(T d) : data(d), next(nullptr) {}
};

template <typename T>
class LinkQueue{
public:
    LinkNode<T>* front;
    LinkNode<T>* rear;

    LinkQueue(){
        front = rear = nullptr;
    }

    ~LinkQueue(){
        LinkNode<T>* pre = front, *p;
        if(pre != nullptr){
            if(pre == rear) delete pre;
            else{
                p = pre -> next;
                while(p != nullptr){
                    delete pre;
                    pre = p; p = p -> next;
                }
                delete pre;
            }
        }
    }

    bool empty(){
        return (front == nullptr);
    }

    bool push(T e){
        LinkNode<T>* p = new LinkNode<T>(e);
        if(empty()) front = rear = p;
        else{
            rear -> next = p;
            rear = p;
        }
        return true;
    }

    bool pop(T& e){
        if(empty()) return false;
        LinkNode<T>* p = front;
        if(front == rear) front = rear = nullptr;
        else front = front -> next;
        e = p -> data;
        delete p;
        return true;
    }

    bool gethead(T& e){
        if(empty()) return false;
        e = front -> data;
        return true;
    }
};