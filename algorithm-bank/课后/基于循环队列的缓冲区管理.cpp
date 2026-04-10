#include <iostream>
using namespace std;

struct Cqueue{
    int capacity;
    int* data;
    int front = 0, rear = 0;
    int count = 0;

    Cqueue(int k) : capacity(k) {
        data = new int[capacity];
    }

    void enqueue(int x){
        data[rear] = x;
        rear = (rear + 1) % capacity;
        if(count == capacity){
            front = (front + 1) % capacity;
            return;
        }
        count++;
    }

    void dequeue(){
        if(count == 0) cout << -1 << endl;
        else {
            cout << data[front] << endl;
            front = (front + 1) % capacity;
            count--;
        }
    }

    void get_oldest(){
        if(count == 0) cout << -1 << endl;
        else cout << data[front] << endl;
    }

    void get_latest(){
        if(count == 0) cout << -1 << endl;
        else cout << data[(rear - 1 + capacity) % capacity] << endl;
    }
};

int main(){
    int k, m;
    cin >> k >> m;
    Cqueue q(k);
    string op;

    while(m--){
        cin >> op;
        if(op == "enqueue"){
            int x; cin >> x;
            q.enqueue(x);
        }
        else if(op == "dequeue"){
            q.dequeue();
        }
        else if(op == "get_oldest") q.get_oldest();
        else if(op == "get_latest") q.get_latest();
    }
    cout << endl;
    return 0;
}