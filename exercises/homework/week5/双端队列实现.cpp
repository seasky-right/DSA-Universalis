#include <iostream>
using namespace std;

const int MAXSIZE = 100005;

struct dequeue{
    int data[MAXSIZE * 2];
    int head = MAXSIZE;
    int tail = MAXSIZE;
    //左闭右开

    void push_f(int x){
        data[--head] = x;
    }

    void push_b(int x){
        data[tail++] = x;
    }

    void pop_f(){
        if(head == tail){
            cout << "EMPTY" << endl;
            return;
        }
        cout << data[head] << endl;
        head++;
    }

    void pop_b(){
        if(head == tail){
            cout << "EMPTY" << endl;
            return;
        }
        cout << data[tail - 1] << endl;
        tail--;
    }

    void front(){
        if(head == tail){
            cout << "EMPTY" << endl;
            return;
        }
        cout << data[head] << endl;
    }

    void back(){
        if(head == tail){
            cout << "EMPTY" << endl;
            return;
        }
        cout << data[tail - 1] << endl;
    }

    void size(){
        cout << tail - head << endl;
    }

};

int main(){
    int n; cin >> n;
    dequeue q;
    while(n--){
        string op;
        cin >> op;
        if(op == "PUSH_FRONT"){
            int x; cin >> x;
            q.push_f(x);
        }
        else if(op == "PUSH_BACK"){
            int x; cin >> x;
            q.push_b(x);
        }
        else if(op == "POP_FRONT"){
            q.pop_f();
        }
        else if(op == "POP_BACK"){
            q.pop_b();
        }
        else if(op == "FRONT"){
            q.front();
        }
        else if(op == "BACK"){
            q.back();
        }
        else if(op == "SIZE"){
            q.size();
        }
    }
    
    return 0;
}
