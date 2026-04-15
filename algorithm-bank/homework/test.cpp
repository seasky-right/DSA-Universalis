#include <iostream>

using namespace std;

const int MaxSize = 1000005;
class dequeue{
public:
    int data[MaxSize * 2];
    int front = MaxSize;
    int rear = MaxSize;

    void push_front(int x){
        data[--front] = x;
    }

    void push_back(int x){
        data[rear++] = x;
    }

    void pop_front(){
        if(front == rear){
            cout << "EMPTY" << endl;
            return;
        }
        cout << data[front++] << endl;
    }

    void pop_back(){
        if(front == rear){
            cout << "EMPTY" << endl;
            return;
        }
        cout << data[--rear] << endl;
    }

    void ftop(){
        if(front == rear){
            cout << "EMPTY" << endl;
            return;
        }
        cout << data[front] << endl;
    }

    void btop(){
        if(front == rear){
            cout << "EMPTY" << endl;
            return;
        }
        cout << data[rear - 1] << endl;
    }

    void size(){
        cout << (rear - front) << endl;
    }

};
dequeue deq;

int main(){
    int m; cin >> m;
    while(m--){
        string op; cin >> op;
        if(op == "PUSH_FRONT"){
            int x; cin >> x;
            deq.push_front(x);
        }else if(op == "PUSH_BACK"){
            int x; cin >> x;
            deq.push_back(x);
        }else if(op == "POP_FRONT")
            deq.pop_front();
        else if(op == "POP_BACK")
            deq.pop_back();
        else if(op == "FRONT")
            deq.ftop();
        else if(op == "BACK")
            deq.btop();
        else if(op == "SIZE")
            deq.size();
    }

    return 0;
}