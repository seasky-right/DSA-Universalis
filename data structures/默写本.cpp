#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

// 顺序栈实现
struct SeqStack {
    vector<int> data;
    int top = -1;

    SeqStack(int n) : data(n) {}

    bool empty() { return top == -1; }
    bool full() { return top == data.size() - 1;}

    bool push(int x) {
        if(full()) {
            return false;
        }
        data[++top] = x;
        return true;
    }

    bool pop() {
        if(empty()) return false;
        cout << data[top--] << endl;
        return true;
    }

    void gettop() {
        if(empty()) cout << "EMPTY" << endl;
        else cout << data[top] << endl;
    }

    int size() {
        return top + 1;
    }
};

// 循环队列实现
struct CQueue {
    vector<int> data;
    int front = 0, rear = 0;
    int count = 0;

    CQueue(int n) : data(n) {}

    bool empty() { return count == 0; }
    bool full() { return count == (int)data.size(); }

    void push(int x) {
        data[rear] = x;
        rear = (rear + 1) % data.size();
        if(full())
            front = (front + 1) % data.size();
        else count++;
    }

    void pop() {
        if(empty()) return;
        front = (front + 1) % data.size();
        count--;
    }

    int get() {
        if(empty()) return -1;
        return data[front];
    }

    int size() { return count; }
};

// 二叉树
struct node {
    int data;
    node* lchild, *rchild;
    node(int d) : data(d), lchild(nullptr), rchild(nullptr) {}
};

node* CreateTree(const string& s, int& i) {
    if(i >= (int)s.size()) return nullptr;
    if(s[i] == ',' || s[i] == ')') return nullptr;

    int num = 0;
    while(i < (int)s.size() && 
        s[i] >= '0' && s[i] <= '9') {
        num = num * 10 + s[i++];
    }

    node* root = new node(num);

    if(i < (int)s.size() && s[i] == '(') {
        i++;
        root -> lchild = CreateTree(s, i);

        if(i < (int)s.size() && s[i] == ',') {
            i++;
            root -> rchild = CreateTree(s, i);
        }

        if(i < (int)s.size() && s[i] == ')')
            i++;
    }

    return root;
}

// 层序遍历
void levelOrder(node* root) {
    if(!root) return;
    queue<node*> qu;
    qu.push(root);

    while(!qu.empty()) {
        node* p = qu.front();
        qu.pop();

        cout << p -> data << " ";

        if(p -> lchild) qu.push(p -> lchild);
        if(p -> rchild) qu.push(p -> rchild);
    }
}

// NLR建树
node* CreateTreeNLR(const vector<int>& pre, const vector<int>& in,
    int& pi, int inL, int inR) {
        if(pi >= pre.size() || inL > inR) return nullptr;

        int d = pre[pi++];
        node* root = new node(d);

        int pos = inL;
        while(pos <= inR && in[pos] != d) pos++;

        root -> lchild = CreateTreeNLR(pre, in, pi, inL, pos - 1);
        root -> rchild = CreateTreeNLR(pre, in, pi, pos + 1, inR);

        return root;
}

//LRN建树
node* CreateTreeLRN(const vector<int>& post, const vector<int>& in,
    int& pi, int inL, int inR) {
        if(pi < 0 || inL > inR) return nullptr;

        int d = post[pi--];
        node* root = new node(d);

        int pos = inL;
        while(pos <= inR && in[pos] != d) pos++;

        // ========== 先右后左 ==========
        root -> rchild = CreateTreeLRN(post, in, pi, inL, pos - 1);
        root -> lchild = CreateTreeLRN(post, in, pi, pos + 1, inR);

        return root;
    }

// 层序+中序建树
node* CreateTreeLI(const vector<int>& level, const vector<int>& in,
    int inL, int inR){
        if(level.empty() || inL > inR) return nullptr;

        int d = level[0];
        node* root = new node(d);

        int pos = inL;
        while(pos <= inR && in[pos] != d) pos++;

        vector<int> leftlevel, rightlevel;
        for(int i = 1; i < level.size(); ++i) {
            int idx = inL;
            while(idx <= inR && in[idx] != level[i]) idx++;

            if(idx < pos) leftlevel.push_back(level[i]);
            else if(idx > pos) rightlevel.push_back(level[i]);
        }

        root -> lchild = CreateTreeLI(leftlevel, in, inL, pos - 1);
        root -> rchild = CreateTreeLI(rightlevel, in, pos + 1, inR);

        return root;
    }

// BST实现
void insert(node*& root, int x) {
    if(!root) {
        root = new node(x);
        return;
    }

    if(x < root -> data) insert(root -> lchild, x);
    else if(x > root -> data) insert(root -> rchild, x);
}

void remove(node*& root, int x) {
    if(!root) return;

    if(x < root -> data) remove(root -> lchild, x);
    else if(x > root -> data) remove(root -> rchild, x);
    else {
        if(!root -> lchild) {
            node* temp = root;
            root = root -> rchild;
            delete temp;
        }
        else if(!root -> rchild) {
            node* temp = root;
            root = root -> rchild;
            delete temp;
        }
        else {
            node* pre = root -> lchild;
            while(pre -> rchild) pre = pre -> rchild;

            root -> data = pre -> data;
            remove(root -> lchild, pre -> data);
        }
    }
}

const int N = 1005;
const int INF = 0x3f3f3f3f;
vector<pair<int, int>> adj[N];

// Prim
int Prim(int n) {
    vector<int> dist(n + 1, INF);
    vector<bool> visited(n + 1, false);

    dist[1] = 0;
    int ans = 0;

    for(int i = 1; i <= n; ++i) {
        int u = -1;

        for(int j = 1; j <= n; ++j) {
            if(!visited[j] && (u == -1 || dist[j] < dist[u])) 
                u = j;
        }

        if(u == -1) break; // 所有可达节点都已访问
        visited[u] = true;
        ans += dist[u];

        for(const pair<int, int>& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if(!visited[v] && w < dist[v]) {
                dist[v] = w;
            }
        }
    }
    return ans;
}

// Kruskal
struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

vector<Edge> edges;
int parent[N];

int Find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}
int Kruskal(int n) {
    sort(edges.begin(), edges.end());
    for(int i = 1; i <= n; ++i) parent[i] = i;

    int ans = 0, count = 0;
    for(const Edge& e : edges) {
        int u = Find(e.u);
        int v = Find(e.v);
        if(u != v) {
            parent[u] = v;
            ans += e.w;
            count++;
            if(count == n - 1) break;
        }
    }
    if(count != n - 1) return -1;
    return ans;
}

// Dijkstra
void Dijkstra(int n, int s) {
    vector<int> dist(n + 1, INF);
    vector<bool> visited(n + 1, false);

    dist[s] = 0;

    for(int i = 1; i <= n; ++i) {
        int u = -1;
        for(int j = 1; j < n; ++j) {
            if(!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        if(u == -1) break;
        visited[u] = true;

        for(auto e : adj[u]) {
            int v = e.first, w = e.second;
            if(!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
}

// Floyd
int dist[N][N];
void Flotd(int n) {
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            dist[i][j] = (i == j ? 0 : INF);

    for(int k = 1; k <= n; ++k) {
        for(int i = 1; i <= n; ++i) {
            if(dist[i][k] == INF) continue;
            for(int j = 1; j <= n; ++j) {
                if(dist[k][j] == INF) continue;
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

// 拓扑排序
void TopSort(int n) {
    vector<int> indegree(n, 0);
    vector<int> topo_order;
    queue<int> qu;
    int count = 0;

    for(int u = 0; u < n; ++u) {
        for(auto& p : adj[u]){
            int v = p.first;
            indegree[v]++;
        }
    }

    for(int u = 0; u < n; ++u) 
        if(indegree[u] == 0) qu.push(u);

    while(!qu.empty()) {
        int u = qu.front(); qu.pop();
        topo_order.push_back(u);
        count++;

        for(auto& p : adj[u]) {
            int v = p.first;
            indegree[v]--;
            if(indegree[v] == 0) qu.push(v);
        }
    }

    if(count != n) return;
}

// 二分查找
int binSearch(vector<int>& arr, int key) {
    int l = 0, r = (int)arr.size() - 1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(arr[mid] == key) return mid;
        else if(arr[mid] < key) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

// 折半插入
void binInsertSort(vector<int>& arr) {
    int n = arr.size();
    for(int i = 1; i < n; ++i) {
        int x = arr[i];
        int l = 0, r = i - 1;

        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(arr[mid] > x) r = mid - 1;
            else l = mid + 1;
        }

        for(int j = i - 1; j >= l; --j) {
            arr[j + 1] == arr[j];
        }
        arr[l] = x;
    }
}

void QuickSort(vector<int>& arr, int low, int high) {
    if(low >= high) return;

    int pivot = arr[low];
    int i = low, j = high;

    while(i < j) {
        while(i < j && arr[j] >= pivot) j--;
        if(i < j) arr[i++] = arr[j];

        while(i < j && arr[i] <= pivot) i++;
        if(i < j) arr[j--] = arr[i];
    }
    arr[i] = pivot;

    QuickSort(arr, low, i - 1);
    QuickSort(arr, i + 1, high);
}

void SelectSort(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for(int j = i + 1; j < n; ++j)
            if(arr[j] < arr[minIdx]) minIdx = j;
        if(minIdx != i) swap(arr[i], arr[minIdx]);
    }
}

// 堆
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if(l < n && arr[l] > arr[largest]) largest = l;
    if(r < n && arr[r] > arr[largest]) largest = r;

    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    for(int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }

    for(int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// 归并
void merge(vector<int>& arr, vector<int>& temp,
    int l, int mid, int r) {
        int i = l, j = mid + 1, k = l;
        while(i <= mid && j <= r) {
            if(arr[i] <= arr[j]) temp[k++] = arr[i++];
            else temp[k++] = arr[j++];
        }

        while(i <= mid) temp[k++] = arr[i++];
        while(j <= r) temp[k++] = arr[j++];

        for(int p = l; p <= r; ++p)
            arr[p] = temp[p];
    }

void mergeSort(vector<int>& arr, vector<int>& temp,
    int l, int r) {
        if(l >= r) return;
        int mid = l + (r - l) / 2;
        mergeSort(arr, temp, l, mid);
        mergeSort(arr, temp, mid + 1, r);
        merge(arr, temp, l, mid, r);
    }