#include <iostream>
using namespace std;

struct heap{
    int data[1000005];
    int size = 0;

    void push(int x){
        int i = size;
        data[size++] = x;
        while(i > 0){
            int parent = (i - 1) / 2;
            if(data[i] < data[parent]){
                swap(data[i], data[parent]);
                i = parent;
            }else break;
        }
    }

    void pop(){
        data[0] = data[--size];
        int i = 0;
        while(i < size){
            int left = i * 2 + 1;
            int right = i * 2 + 2;
            int smallest = i;
            if (left < size && data[left] < data[smallest]) smallest = left;
            if (right < size && data[right] < data[smallest]) smallest = right;
            if (smallest != i) {
                swap(data[i], data[smallest]);
                i = smallest;
            } else break;
        } 
    }

    void top(){
        cout << data[0] << endl;
    }
};
heap h;

int main(){
    int n; cin >> n;
    while(n--){
        int op; cin >> op;
        if(op == 1){
            int x; cin >> x;
            h.push(x);
        }else if(op == 2) h.top();
        else if(op == 3) h.pop();
    }

    return 0;
}
