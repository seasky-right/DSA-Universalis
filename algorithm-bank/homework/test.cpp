#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {}
    Node(int d) : data(d), next(nullptr) {}
};

int main(){
    cout << "Hello World!" << endl;
    return 0;
}

//if-else分支跳出后不会继续运行。

//注意条件顺序同时也是判断的数据。