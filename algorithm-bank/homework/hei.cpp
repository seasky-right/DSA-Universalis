#include <iostream>
using namespace std;

class Queue {
private:
    int* array;
    int maxSize;
    int front, rear, size;

public:
    Queue(int s) : maxSize(s),
front(0), rear(-1), size(0) {
        array = new int[maxSize];
    }

    ~Queue() {
        delete[] array;
    }

    void IN(int x) {
        if (size == maxSize) return;
        rear = (rear + 1) % maxSize;
        array[rear] = x;
        size++;
    }

    void OUT() {
        if (size == 0) return;
        front = (front + 1) % maxSize;
        size--;
    }

    int GET() {
        if (size == 0) return -1;
        return array[front];
    }

    int SIZE() {
        return size;
    }
};

int main() {
    int maxSize, k;
    cin >> maxSize >> k;

    Queue q(maxSize);

    for (int i = 0; i < k; ++i) {
        string operation;
        cin >> operation;
        if (operation == "IN") {
            int x;
            cin >> x;
            q.IN(x);
        } else if (operation == "OUT") {
            q.OUT();
        } else if (operation == "GET") {
            cout << q.GET() << endl;
        } else if (operation == "SIZE") {
            cout << q.SIZE() << endl;
        }
    }

    return 0;
}