#include <iostream>
using namespace std;

const int MaxSize = 10;
template <typename T>
class SeqList {
public:
    T* data;
    int length;
    int capacity;

    SeqList(){
        data = new T[MaxSize];
        capacity = MaxSize;
        length = 0;
    }

    SeqList(const SeqList<T>& s){
        length = s.length;
        capacity = s.capacity;
        data = new T[capacity];
        for(int i = 0; i < length; ++i){
            data[i] = s.data[i];
        }
    }

    ~SeqList(){
        delete [] data;
    }

    void ReCap(int newSize) {
        if(newSize <= 0) return;
        T* olddata = data;
        data = new T[newSize]; //动态数组 顺序：1搬新家 2拆老房
        capacity = newSize;
        for(int i = 0; i < length; i++){
            data[i] = olddata[i];
        }
        delete [] olddata;
    }

    void CreateList(T a[], int n){
        for(int i = 0; i < n; ++i){
            if(length == capacity) ReCap(2 * length);
            data[length] = a[i];
            length++;
        }
    }

    void Add(T e){
        if(length == capacity) ReCap(2 * length);
        data[length] = e;
        length++;
    }

    int GetNo(T e){
        for(int i = 0; i < length; ++i){
            if(data[i] == e) return i;
        }
        return -1;
    }

    void Insert(int i, T e){
        if(i < 0 || i > length) return;
        if(length == capacity) ReCap(2 * length);
        for(int j = length - 1; j >= i; --j){
            data[j + 1] = data[j];
        }
        data[i] = e;
        length++;
    }

    void Delete(int i){
        if(i < 0 || i >= length) return;
        for(int j = i; j < length - 1; ++j){
            data[j] = data[j + 1];
        }
        length--;
        if(capacity > MaxSize && length < capacity / 2) ReCap(capacity / 2);
    }

};

int main() {
    // 1. 创建一个存整数的顺序表
    SeqList<int> myList;
    
    // 2. 疯狂往里面加东西，测试你的 ReCap 扩容有没有用！
    // 你的 MaxSize 是 10，我们故意加 12 个数进去
    for(int i = 0; i < 12; i++) {
        myList.Add(i * 10); 
    }
    
    // 3. 打印出来看看，扩容成功了吗？
    cout << "当前顺序表长度: " << myList.length << endl;
    cout << "当前顺序表容量: " << myList.capacity << endl; // 应该变成 20 了
    
    return 0;
}