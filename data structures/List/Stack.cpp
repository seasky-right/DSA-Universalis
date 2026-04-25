#include <iostream>
using namespace std;

const int MaxSize = 105;

template <typename T>
class SqStack{
private:
    T* data;
    int top;  //栈顶指针（int型，表示数组下标）

public:
    SqStack(){
        data = new T[MaxSize];
        top = -1;
    }

    ~SqStack(){
        delete [] data;
    }

    bool empty(){
        return top == -1;
    }

    bool push(T e){
        if(top == MaxSize - 1) return false;
        top++;
        data[top] = e;
        return true;
    }

    bool pop(T& e){
        if(top == -1) return false;
        e = data[top--];
        return true;
    }

    bool gettop(T& e){
        if(empty()) return false;
        e = data[top];
        return true;
    }
};

template <typename T>
struct LinkNode{
    T data;
    LinkNode* next;
    LinkNode() : next(nullptr){}
    LinkNode(T d) : data(d), next(nullptr){}
};

template <typename T>
class LinkStack{
public:
    LinkNode<T>* head;

    LinkStack(){
        head = new LinkNode<T>();
    }

    ~LinkStack(){
        LinkNode<T>* pre = head, *p = pre -> next;
        while(p != nullptr){
            delete pre;
            pre = p, p = p -> next;
        }
        delete pre; //别忘了最后一个
    }

    // 禁用拷贝构造函数
    LinkStack(const LinkStack& s) = delete;

    // 禁用赋值操作符
    LinkStack& operator=(const LinkStack& s) = delete;

    bool empty(){
        return(head -> next == nullptr);
    }

    bool push(T e){
        LinkNode<T>* p = new LinkNode<T>(e);
        p -> next = head -> next;
        head -> next = p;
        return true;
    }

    bool pop(T& e){
        LinkNode<T>* p;
        if(empty()) return false;
        p = head -> next;
        e = p -> data;
        head -> next = p -> next;
        delete p;
        return true;
    }

    bool gettop(T& e){
        LinkNode<T>* p;
        if(empty()) return false;
        p = head -> next;
        e = p -> data;
        return true;
    }
};

//迷宫问题（深度优先搜索）
const int Max = 10;
int maze[Max][Max] = {
    {0, 1, 0, 0},
    {0, 1, 0, 1},
    {0, 0, 0, 1},
    {1, 1, 0, 0}
};
int m = 4, n = 4;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

struct Box{
    int i;
    int j;
    int di;
    Box() : i(0), j(0), di(0) {}
    Box(int x, int y, int d) : i(x), j(y), di(d) {}
};

bool getPath(int x, int y, SqStack<Box>& path){
    if(x < 0 || x >= m || y < 0 || y >= n || maze[x][y] != 0) return false;

    Box box(x, y, 0);
    path.push(box);
    maze[x][y] = 1; //标记为已访问

    while(!path.empty()){
        Box topBox;
        path.gettop(topBox);
        int i = topBox.i, j = topBox.j, di = topBox.di;

        if(i == m - 1 && j == n - 1) return true; //到达终点

        bool found = false;
        for(int k = di; k < 4; k++){
            int newX = i + dx[k];
            int newY = j + dy[k];
            if(newX >= 0 && newX < m && newY >= 0 && newY < n && maze[newX][newY] == 0){
                path.pop(topBox); //更新当前节点，下次从k+1继续试
                topBox.di = k + 1;
                path.push(topBox);

                Box newBox(newX, newY, 0);
                path.push(newBox); //将新节点入栈
                maze[newX][newY] = 1; //标记为已访问
                found = true;
                break; //跳出循环，继续处理新节点
            }
        }

        if(!found){
            path.pop(topBox); //四个方向都试完，回溯
        }
    }
    return false; //没有路径
}

bool getPath(int x, int y){
    SqStack<Box> path;
    return getPath(x, y, path);
}

void disPath(SqStack<Box>& s){
    SqStack<Box> temp;
    Box box;
    while(!s.empty()){
        s.pop(box);
        temp.push(box);
    }

    while(!temp.empty()){
        temp.pop(box);
        cout << "(" << box.i << ", " << box.j << ")" << endl;
    }
}
