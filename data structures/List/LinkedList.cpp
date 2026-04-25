#include <iostream>

using namespace std;

template <typename T>
struct LinkNode {
    T data;
    LinkNode<T>* next;
};//节点数据类型，用于串接成表

template <typename T>
class LinkedList {
public:
    LinkNode<T>* head;

    LinkedList(){
        head = new LinkNode<T>;
        head->next = nullptr;
    }

    ~LinkedList(){
        LinkNode<T>* p = head;
        while(p){
            LinkNode<T>* temp = p;  //保存当前节点地址，删除后无法访问
            p = p->next;
            delete temp;
        }
    }

    void CreateListF(T a[], int n){
        for(int i = 0; i < n; ++i){
            LinkNode<T>* s = new LinkNode<T>;
            s->data = a[i];
            s->next = head->next;
            head->next = s;
        }
    }

    void CreateListR(T a[], int n){
        LinkNode<T>* r = head, *s; //由于尾节点动态变化，需要一个尾指针
        for(int i = 0; i < n; ++i){
            s = new LinkNode<T>;
            s->data = a[i];
            r->next = s; //改变r->next的指向
            r = s; //改变*r指向的位置至s
        }
        r->next = nullptr; //尾节点的next指向nullptr
    }

    LinkNode<T>* Geti(int i){
        if(i < 0) return nullptr;
        LinkNode<T>* p = head;
        while(p && i){
            p = p->next;
            i--;
        }
        return p;
    }

    void Add(T e){
        LinkNode<T>* s = new LinkNode<T>;
        s->data = e;
        LinkNode<T>* p = head; //从头结点开始遍历，使用指针
        while(p->next){
            p = p->next;
        }
        p->next = s;
        s->next = nullptr;
    }

    void Insert(int i, T e){
        if(i < 0) return;
        LinkNode<T>* p = Geti(i - 1);
        if(!p) return;
        LinkNode<T>* s = new LinkNode<T>;
        s->data = e;
        s->next = p->next;  
        p->next = s;
    }

    void Delete(int i){
        if(i < 0) return;
        LinkNode<T>* p = Geti(i - 1);
        if(!p || !p->next) return;
        LinkNode<T>* temp = p->next; //保存待删除节点地址，删除后无法访问
        p->next = temp->next; //改变p->next的指向，跳过待删除节点
        delete temp; //删除待删除节点
    }
    
    void Displist(){
        LinkNode<T>* p = head->next; //必须从实际首节点开始遍历，头结点不存数据
        while(p){
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
};