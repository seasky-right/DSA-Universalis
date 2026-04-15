#include <iostream>

using namespace std;

class Myqueue{
public:
    int* data;
    int front;
    int rear;
    int capacity;

    Myqueue(int c){
        capacity = c;
        data = new int[c];
        front = rear = 0;
    }

    ~Myqueue(){
        delete [] data;
    }

    void push(int x){
        if((rear+1) % capacity == front) return;
        rear = (rear+1) % capacity;
        data[rear] = x;
    }

    void pop(){
        if(front == rear) return;
        front = (front+1) % capacity;
    }

    void top(){
        if(front == rear){
            cout << -1 << endl;
            return;
        }
        int head = (front+1) % capacity;
        cout << data[head] << endl;
    }

    void size(){
        cout << ((rear + capacity - front) % capacity) << endl;
    }

};

int main(){
    int m, k; 
    if(!(cin >> m >> k)) return 0;
    Myqueue que(m);
    while(k--){
        string op; cin >> op;
        if(op == "IN"){
            int x; cin >> x;
            que.push(x);
        }else if(op == "OUT") que.pop();
        else if(op == "GET") que.top();
        else if(op == "SIZE") que.size();
    }
    cout << endl;
    return 0;
}