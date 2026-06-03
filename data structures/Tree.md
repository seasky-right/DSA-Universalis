# 二叉树

## 通用结构体

```cpp
struct BTNode {
    int data;                     // char 或 int，按题目而定
    BTNode* lchild, *rchild;
    BTNode(int d) : data(d), lchild(nullptr), rchild(nullptr) {}
};
```

---

## 建树

### 1. 括号表示法（广义表）

输入形如 `A(B,C(D,E))` 或 `1(2,3(4,5))`，括号内是左右孩子，逗号分隔。

#### 1.1 递归版

```cpp
BTNode* CreateBTree(const string& str, int& i) {
    if(i >= str.size()) return nullptr;
    if(str[i] == ',' || str[i] == ')') return nullptr;

    BTNode* s = new BTNode(str[i]);  // char 版
    i++;

    if(i < str.size() && str[i] == '(') {
        i++;
        s->lchild = CreateBTree(str, i);
        if(str[i] == ',') {
            i++;
            s->rchild = CreateBTree(str, i);
        }
        if(str[i] == ')') i++;
    }
    return s;
}
```

**如果数据是 int（多位数）**，把节点创建改成：

```cpp
int num = 0;
while(i < str.size() && str[i] >= '0' && str[i] <= '9')
    num = num * 10 + (str[i++] - '0');
BTNode* s = new BTNode(num);
// 然后同样判断 '(' ...
```

**调用**：
```cpp
string str; cin >> str;
int i = 0;
BTNode* root = CreateBTree(str, i);
```

**原理**：每读一个字符建节点，若后面紧跟 `(` 说明有子树，递归建左；若遇 `,` 转去建右；遇 `)` 表示当前子树结束返回。

#### 1.2 栈迭代版

```cpp
BTNode* CreateBTree(string str) {
    stack<BTNode*> st; // 存储当前处理的父节点
    BTNode* p = nullptr, *root = nullptr;
    bool flag = true;  // true=左, false=右
    int i = 0;

    while(i < str.size()) {
        switch(str[i]) {
        case '(':
            st.push(p);
            flag = true;
            break;
        case ')':
            st.pop();
            break;
        case ',':
            flag = false;
            break;
        default:
            p = new BTNode(str[i]);        // char 版
            // 如果 int 多位数，同递归版的 while 累加
            if(!root) root = p;
            else if(!st.empty()) {
                if(flag) st.top()->lchild = p;
                else     st.top()->rchild = p;
            }
            break;
        }
        i++;
    }
    return root;
}
```

**原理**：栈顶始终是"当前正在填孩子的父节点"。遇 `(` 将当前节点压栈（它将成为后续节点的父节点）；遇 `,` 切换到填右孩子；遇 `)` 弹出表示该子树填完；遇字母则创建节点并挂到栈顶的对应侧。

**递归 vs 迭代对比**：

|      | 递归                     | 栈迭代                  |
|------|--------------------------|-------------------------|
| 代码量 | ~15 行                  | ~25 行                  |
| 直观度 | 更好理解                 | 需要维护 flag/stack 状态 |
| 适用   | 一般场景                 | 要求非递归 或 树极深时   |

---

### 2. 双序列重建

#### 2.1 前序 + 中序 → 二叉树

```cpp
BTNode* CreateBTreeNLR(
    const vector<char>& pre,   // 前序
    const vector<char>& in,    // 中序
    int& i, int inL, int inR        // &i=前序起点, inL=中序起点, inR=中序终点
) {
    if(inL > inR) return nullptr;

    int d = pre[i++]; // 探针取值后立刻进一步
    BTNode* root = new node(d);

    int pos = inL;
    while(in[pos] != d) pos++;

    root->lchild = CreateBTreeNLR(pre, in, i, inL, pos - 1);
    root->rchild = CreateBTreeNLR(pre, in, i, pos + 1, inR);

    return root;
}
```

**调用**：
```cpp
int i = 0, inL = 0, inR = in.size();
BTNode* root = CreateBTreeNLR(pre, in, i, inL, inR);
```

**原理**：前序第一个是根，在中序中找到根的位置 → 左边全是左子树，右边全是右子树 → 递归。

前序分割示意：
```
前序: [根][  左子树  ][  右子树  ]
      i   i+1..i+k   i+k+1..i+n-1

中序: [  左子树  ][根][  右子树  ]
      j..j+k-1    p    p+1..p+n-k-1
```

#### 2.2 后序 + 中序 → 二叉树

```cpp
BTNode* CreateBTreeLRN(
    const vector<char>& post,  // 后序
    const vector<char>& in,    // 中序
    int& i, int inL, int inR        // &i=后序终点, inL=中序起点, inR=中序终点
) {
    if(inL > inR) return nullptr;

    int d = post[i--]; // 后序从最后一个开始
    BTNode* root = new BTNode(d);

    int pos = inL;
    while(in[pos] != d) pos++;

    // 注意：倒序阅读，必须先右后左！！！
    root->rchild = CreateBTreeLRN(post, in, i, pos + 1, inR);
    root->lchild = CreateBTreeLRN(post, in, i, inL, pos - 1);

    return root;
}
```

**调用**：
```cpp
int i = post.size() - 1, inL = 0, inR = in.size() - 1;
BTNode* root = CreateBTreeLRN(post, in, i, inL, inR);
```

**与前序版本的区别**：
对比维度	前序 + 中序 (Preorder + Inorder)	后序 + 中序 (Postorder + Inorder)	底层物理原因
探针起点	int idx = 0;	int idx = post.size() - 1;	根节点在序列中的位置（前序在最左，后序在最右）
探针走向	int root_val = pre[idx++];	int root_val = post[idx--];	剥离根节点后，剩下的数据在哪里（前序在右侧，后序在左侧）
递归顺序 (最易错点)	先左后右1. root->lchild = ...2. root->rchild = ...	先右后左1. root->rchild = ...2. root->lchild = ...	探针推进一步后，迎面撞上的第一团数据是谁（前序顺着读下一个是左子树，后序逆着读上一个是右子树）

后序分割示意：
```
后序: [  左子树  ][  右子树  ][根]
      i..i+k-1   i+k..i+n-2  i+n-1
```

#### 2.3 层次 + 中序 → 二叉树

```cpp
BTNode* CreateBTreeLevel(
    const vector<char>& level, // 层次
    const vector<char>& in,    // 中序
    int inL, int inR           // 中序当前处理区间
) {
    if(level.empty() || inL > inR) return nullptr;

    BTNode* root = new BTNode(level[0]);
    if(inL == inR) return root;

    // 找 root 在中序中的位置
    int pos = inL;
    while(pos <= inR && in[pos] != level[0]) pos++;

    // 将剩余层次元素按"在中序中位于 root 左/右"分配到两子序列
    vector<char> leftLev, rightLev;
    for(int i = 1; i < level.size(); i++) {
        int idx = inL;
        while(idx <= inR && in[idx] != level[i]) idx++;
        if(idx < pos)      leftLev.push_back(level[i]);
        else if(idx > pos) rightLev.push_back(level[i]);
    }

    root->lchild = CreateBTreeLevel(leftLev, in, inL, pos - 1);
    root->rchild = CreateBTreeLevel(rightLev, in, pos + 1, inR);
    return root;
}
```

**调用**：
```cpp
BTNode* root = CreateBTreeLevel(level, in, 0, in.size() - 1);
```

**原理**：层序第一个是根，在中序中找到根 → 将剩余层序元素分配到左右两个子序列 → 子序列的第一个又是各自子树的根 → 递归。

**三种双序列重建对比**：

|          | 根的位置                | 分割依据          |
|----------|------------------------|-------------------|
| 前序+中序 | `pre[i]`（第一）       | 中序中找根，算 k  |
| 后序+中序 | `post[i+n-1]`（最后）  | 中序中找根，算 k  |
| 层次+中序 | `level[0]`（第一）     | 中序中找根，剩余元素按左右分区 |

---

### 3. 先序递归 + 哨兵（流式输入）

最常用模式，输入是带空节点标记的先序序列，空格分隔。

```cpp
BTNode* CreateBTree(istringstream& iss) {
    int x;
    if(!(iss >> x) || x == -1) return nullptr;

    BTNode* root = new BTNode(x);
    root->lchild = CreateBTree(iss);
    root->rchild = CreateBTree(iss);
    return root;
}
```

**调用**：
```cpp
string line; getline(cin, line);
istringstream iss(line);
BTNode* root = CreateBTree(iss);
```

**哨兵变体**：char 类型时用 `#` 代替 `-1`：
```cpp
char x;
if(!(iss >> x) || x == '#') return nullptr;
```

**原理**：流式读入即前序遍历建树——先读根，再递归左，再递归右。遇到哨兵说明是空子树，返回 `nullptr`。

---

### 4. 层次数组 + BFS 队列构建

输入是层序遍历数组（LeetCode 风格），`-1` 或 `#` 表示空。

#### 4.1 vector<int> 版（推荐）

```cpp
BTNode* CreateBTree(const vector<int>& arr) {
    if(arr.empty() || arr[0] == -1) return nullptr;

    queue<BTNode*> qu;
    BTNode* root = new BTNode(arr[0]);
    qu.push(root);

    int idx = 1;
    while(!qu.empty() && idx < arr.size()) {
        BTNode* cur = qu.front(); qu.pop();

        if(idx < arr.size() && arr[idx] != -1) {
            cur->lchild = new BTNode(arr[idx]);
            qu.push(cur->lchild);
        }
        idx++;

        if(idx < arr.size() && arr[idx] != -1) {
            cur->rchild = new BTNode(arr[idx]);
            qu.push(cur->rchild);
        }
        idx++;
    }
    return root;
}
```

#### 4.2 string 版（逗号分隔，`#` 为空）

输入形如 `"1,2,3,#,#,4,5"`，先 `getline(cin, s)` 再按逗号分割解析。

```cpp
vector<string> split(const string& s, char delim) {
    vector<string> res;
    string token;
    istringstream iss(s);
    while(getline(iss, token, delim))
        res.push_back(token);
    return res;
}

BTNode* CreateBTree(const string& s) {
    vector<string> nodes = split(s, ',');
    if(nodes.empty() || nodes[0] == "#") return nullptr;

    queue<BTNode*> qu;
    BTNode* root = new BTNode(stoi(nodes[0]));
    qu.push(root);

    int idx = 1;
    while(!qu.empty() && idx < nodes.size()) {
        BTNode* cur = qu.front(); qu.pop();

        if(nodes[idx] != "#") {
            cur->lchild = new BTNode(stoi(nodes[idx]));
            qu.push(cur->lchild);
        }
        idx++;

        if(idx < nodes.size() && nodes[idx] != "#") {
            cur->rchild = new BTNode(stoi(nodes[idx]));
            qu.push(cur->rchild);
        }
        idx++;
    }
    return root;
}
```

---

### 5. BST / AVL（顺序插入）

#### 5.1 BST 插入

```cpp
BTNode* InsertBST(BTNode* root, int key) {
    if(!root) return new BTNode(key);
    if(key < root->data)
        root->lchild = InsertBST(root->lchild, key);
    else if(key > root->data)
        root->rchild = InsertBST(root->rchild, key);
    return root;  // 相等不插入
}

BTNode* CreateBST(const vector<int>& arr) {
    BTNode* root = nullptr;
    for(int key : arr) root = InsertBST(root, key);
    return root;
}
```

#### 5.2 AVL 插入（带旋转）

```cpp
int Height(BTNode* p) { return p ? p->height : 0; }
int BF(BTNode* p) { return p ? Height(p->lchild) - Height(p->rchild) : 0; }

void RightRotate(BTNode*& p) {
    BTNode* L = p->lchild;
    p->lchild = L->rchild;
    L->rchild = p;
    p->height = 1 + max(Height(p->lchild), Height(p->rchild));
    L->height = 1 + max(Height(L->lchild), Height(L->rchild));
    p = L;
}

void LeftRotate(BTNode*& p) {
    BTNode* R = p->rchild;
    p->rchild = R->lchild;
    R->lchild = p;
    p->height = 1 + max(Height(p->lchild), Height(p->rchild));
    R->height = 1 + max(Height(R->lchild), Height(R->rchild));
    p = R;
}

void InsertAVL(BTNode*& root, int key) {
    if(!root) { root = new BTNode(key); return; }
    if(key < root->data) InsertAVL(root->lchild, key);
    else if(key > root->data) InsertAVL(root->rchild, key);
    else return;

    root->height = 1 + max(Height(root->lchild), Height(root->rchild));
    int bf = BF(root);

    if(bf > 1) {                              // 左高
        if(BF(root->lchild) >= 0)             // LL
            RightRotate(root);
        else {                                // LR
            LeftRotate(root->lchild);
            RightRotate(root);
        }
    } else if(bf < -1) {                      // 右高
        if(BF(root->rchild) <= 0)             // RR
            LeftRotate(root);
        else {                                // RL
            RightRotate(root->rchild);
            LeftRotate(root);
        }
    }
}
```

**四种旋转记忆口诀**：
- **LL**：右旋根（左子太高，左子也是左高）
- **RR**：左旋根（右子太高，右子也是右高）
- **LR**：先左旋左子，再右旋根
- **RL**：先右旋右子，再左旋根

---

### 6. 哈夫曼树（最小堆求 WPL）

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
for(int i = 0; i < n; i++) { int x; cin >> x; pq.push(x); }

int wpl = 0;
while(pq.size() > 1) {
    int a = pq.top(); pq.pop();
    int b = pq.top(); pq.pop();
    int sum = a + b;
    wpl += sum;
    pq.push(sum);
}
cout << wpl << endl;
```

---

### 7. 表达式树（后缀表达式，栈构建）

```cpp
BTNode* CreateBTree(string postfix) {
    stack<BTNode*> st;
    for(char c : postfix) {
        BTNode* p = new BTNode(c);
        if(c >= 'A' && c <= 'Z') {        // 运算符：弹两个做孩子
            BTNode* a = st.top(); st.pop();
            BTNode* b = st.top(); st.pop();
            p->lchild = b;
            p->rchild = a;
        }
        st.push(p);                       // 操作数直接压栈
    }
    return st.top();
}
```

---

### 建树方式速查表

| # | 建树方式 | 输入示例 | 核心思路 |
|---|---------|---------|---------|
| 1 | 括号表示法（递归） | `A(B,C(D,E))` | 读字符→遇 `(`递归子树→遇 `,`转右→遇 `)`返回 |
| 2 | 括号表示法（栈） | `A(B,C(D,E))` | 栈存父节点，flag 控制左/右 |
| 3 | 前序+哨兵 | `1 2 -1 -1 3 -1 -1` | 流式递归，哨兵=空 |
| 4 | 层次数组+BFS | `[1,2,3,null,null,4,5]` | 队列逐层挂左右孩子 |
| 5 | 前序+中序 | 两个序列 | `pre[0]`是根→中序分割→递归 |
| 6 | 后序+中序 | 两个序列 | `post[last]`是根→中序分割→递归 |
| 7 | 层次+中序 | 两个序列 | `level[0]`是根→剩余按中序左右分区→递归 |
| 8 | BST 插入 | 一组 key | 逐个 Insert（小往左大往右） |
| 9 | AVL 插入 | 一组 key | 插入+回溯平衡（LL/LR/RR/RL） |
| 10 | 哈夫曼树 | 一组权值 | 小根堆反复合并最小两个 |
| 11 | 表达式树 | 后缀表达式 | 操作数压栈，运算符弹二合一 |

---

## 遍历

### 递归遍历

三种遍历只有 `cout` 的位置不同——先序在递归前，中序在中间，后序在递归后。

```cpp
void PreOrder(BTNode* root) {
    if(!root) return;
    cout << root->data << " ";
    PreOrder(root->lchild);
    PreOrder(root->rchild);
}

void InOrder(BTNode* root) {
    if(!root) return;
    InOrder(root->lchild);
    cout << root->data << " ";
    InOrder(root->rchild);
}

void PostOrder(BTNode* root) {
    if(!root) return;
    PostOrder(root->lchild);
    PostOrder(root->rchild);
    cout << root->data << " ";
}
```

### 非递归遍历

**前序（栈）**：根入栈 → 弹出访问 → 先压右再压左。

```cpp
void PreOrder(BTNode* root) {
    if(!root) return;
    stack<BTNode*> st;
    st.push(root);
    while(!st.empty()) {
        BTNode* p = st.top(); st.pop();
        cout << p->data << " ";
        if(p->rchild) st.push(p->rchild);  // 先右
        if(p->lchild) st.push(p->lchild);  // 后左（先出栈）
    }
}
```

**中序（栈）**：沿左链一路到底，沿途压栈 → 弹出访问 → 转向右子树。

```cpp
void InOrder(BTNode* root) {
    stack<BTNode*> st;
    BTNode* p = root;
    while(!st.empty() || p) {
        while(p) {                   // 沿左链走到底
            st.push(p);
            p = p->lchild;
        }
        p = st.top(); st.pop();      // 弹出访问
        cout << p->data << " ";
        p = p->rchild;               // 转向右子树
    }
}
```

**后序（双栈法，最简洁）**：改造前序（根→右→左），将结果压入第二个栈，最后全部弹出即得（左→右→根）。

```cpp
void PostOrder(BTNode* root) {
    if(!root) return;
    stack<BTNode*> st;
    stack<int> res;                  // 存结果
    st.push(root);
    while(!st.empty()) {
        BTNode* p = st.top(); st.pop();
        res.push(p->data);
        if(p->lchild) st.push(p->lchild);
        if(p->rchild) st.push(p->rchild);
    }
    while(!res.empty()) {
        cout << res.top() << " ";
        res.pop();
    }
}
```

> 后序还有传统的单栈+标记法，代码更长。双栈法本质是 `(根右左) 的逆序 = 左右根`，考试首选。

**层次（队列 BFS）**：

```cpp
void LevelOrder(BTNode* root) {
    if(!root) return;
    queue<BTNode*> qu;
    qu.push(root);
    while(!qu.empty()) {
        BTNode* p = qu.front(); qu.pop();
        cout << p->data << " ";
        if(p->lchild) qu.push(p->lchild);
        if(p->rchild) qu.push(p->rchild);
    }
}
```

### 非递归遍历速记

| 遍历 | 数据结构 | 核心技巧 |
|------|---------|---------|
| 前序 | 栈 | 根弹出 → 先压右再压左 |
| 中序 | 栈 | 沿左链走到底 → 弹出一个 → 转右 |
| 后序 | 双栈 | 改造前序（先左后右）→ 逆序输出 |
| 层次 | 队列 | 出队访问 → 左右孩子入队 |

---

## 基础属性

```cpp
// 深度/高度
int Depth(BTNode* root) {
    if(!root) return 0;
    return max(Depth(root->lchild), Depth(root->rchild)) + 1;
}

// 节点总数
int CountNodes(BTNode* root) {
    if(!root) return 0;
    return 1 + CountNodes(root->lchild) + CountNodes(root->rchild);
}

// 叶子节点数
int CountLeaves(BTNode* root) {
    if(!root) return 0;
    if(!root->lchild && !root->rchild) return 1;
    return CountLeaves(root->lchild) + CountLeaves(root->rchild);
}

// 单分支节点数
int CountSingle(BTNode* root) {
    if(!root) return 0;
    int isSingle = (!root->lchild != !root->rchild) ? 1 : 0;
    return isSingle + CountSingle(root->lchild) + CountSingle(root->rchild);
}
```

> 单分支判据：`(!lchild != !rchild)` —— 一个为真一个为假，即一个存在一个不存在。

---

## 镜像、对称、相同、复制

```cpp
// 镜像翻转
void Mirror(BTNode* root) {
    if(!root) return;
    swap(root->lchild, root->rchild);
    Mirror(root->lchild);
    Mirror(root->rchild);
}

// 判断是否镜像对称（双指针法）
bool IsMirror(BTNode* p, BTNode* q) {
    if(!p && !q) return true;
    if(!p || !q) return false;
    if(p->data != q->data) return false;
    return IsMirror(p->lchild, q->rchild) &&   // 错位比较！
           IsMirror(p->rchild, q->lchild);
}
bool IsSymmetric(BTNode* root) {
    return !root || IsMirror(root->lchild, root->rchild);
}

// 判断两棵树是否相同
bool IsSame(BTNode* t1, BTNode* t2) {
    if(!t1 && !t2) return true;
    if(!t1 || !t2) return false;
    if(t1->data != t2->data) return false;
    return IsSame(t1->lchild, t2->lchild) &&
           IsSame(t1->rchild, t2->rchild);
}

// 复制树
BTNode* CopyTree(BTNode* root) {
    if(!root) return nullptr;
    BTNode* p = new BTNode(root->data);
    p->lchild = CopyTree(root->lchild);
    p->rchild = CopyTree(root->rchild);
    return p;
}
```

> **关键区分**：`IsSame` 的递归是 `(l, l) && (r, r)`（同侧），`IsMirror` 的递归是 `(l, r) && (r, l)`（交叉）。

---

## LCA（最近公共祖先）

"左右支返回值"模式的代表题——通过递归返回值告知父节点"你管辖的子树里有没有目标"。

```cpp
BTNode* LCA(BTNode* root, BTNode* p, BTNode* q) {
    if(!root) return nullptr;
    if(root == p || root == q) return root;     // 命中，向上报告

    BTNode* left  = LCA(root->lchild, p, q);
    BTNode* right = LCA(root->rchild, p, q);

    if(left && right) return root;              // 左右各有一个，root 就是 LCA
    return left ? left : right;                 // 只有一边有，继续上传
}
```

> 前提是树中已确认 p、q 存在。如果可能不存在，需要额外遍历确认。

---

## 序列化与反序列化（`#` 哨兵）

先序遍历，`#` 表示空。序列化和反序列化互逆。

```cpp
// 序列化
string Serialize(BTNode* root) {
    if(!root) return "#";
    return to_string(root->data) + "," +
           Serialize(root->lchild) + "," +
           Serialize(root->rchild);
}

// 反序列化
BTNode* Deserialize(istringstream& iss) {
    string token;
    if(!getline(iss, token, ',') || token == "#") return nullptr;
    BTNode* root = new BTNode(stoi(token));
    root->lchild = Deserialize(iss);
    root->rchild = Deserialize(iss);
    return root;
}
```

---

## BST 操作

### 查找

```cpp
BTNode* SearchBST(BTNode* root, int key) {
    if(!root || root->data == key) return root;
    if(key < root->data) return SearchBST(root->lchild, key);
    else                 return SearchBST(root->rchild, key);
}
```

### 删除（三种形态）

```cpp
bool DeleteBST(BTNode*& root, int key) {
    if(!root) return false;

    if(key < root->data) return DeleteBST(root->lchild, key);
    else if(key > root->data) return DeleteBST(root->rchild, key);

    // 命中 root
    BTNode* temp = root;

    if(!root->rchild) {              // 形态1: 无右子 → 左子顶替
        root = root->lchild;
        delete temp;
    } else if(!root->lchild) {       // 形态2: 无左子 → 右子顶替
        root = root->rchild;
        delete temp;
    } else {                         // 形态3: 双子 → 前驱顶替
        BTNode* q = root->lchild;
        while(q->rchild) q = q->rchild;   // 左子树的最右节点（前驱）
        root->data = q->data;              // 值覆盖
        DeleteBST(root->lchild, q->data);  // 删除前驱
    }
    return true;
}
```

> 删除三形态：**叶子/单支直接替换，双支找前驱覆盖**。

---

## 判断完全二叉树

技巧：层次遍历中，**一旦遇到一个空节点，之后不能再出现非空节点**。

```cpp
bool IsCompleteTree(BTNode* root) {
    if(!root) return true;
    queue<BTNode*> qu;
    qu.push(root);
    bool metNull = false;

    while(!qu.empty()) {
        BTNode* p = qu.front(); qu.pop();
        if(!p) metNull = true;
        else {
            if(metNull) return false;       // 空节点后出现非空 → 不是完全
            qu.push(p->lchild);
            qu.push(p->rchild);
        }
    }
    return true;
}
```

---

## 线索二叉树（中序线索化）

将空指针（`nullptr`）改为指向前驱/后继的线索，`ltag`/`rtag` 标记是指向孩子还是线索。

```cpp
struct BthNode {
    char data;
    BthNode *lchild, *rchild;
    int ltag, rtag;                // 0=孩子, 1=线索
};

void Thread(BthNode* p, BthNode*& pre) {
    if(!p) return;
    Thread(p->lchild, pre);

    if(!p->lchild) { p->lchild = pre; p->ltag = 1; }
    if(pre && !pre->rchild) { pre->rchild = p; pre->rtag = 1; }

    pre = p;
    Thread(p->rchild, pre);
}
```

---

## 哈夫曼编码

从哈夫曼树的根出发，向左走加 `'0'`，向右走加 `'1'`，到叶子时输出编码。

```cpp
void HuffmanCode(BTNode* root, string code) {
    if(!root) return;
    if(!root->lchild && !root->rchild) {      // 叶子节点
        cout << (char)root->data << ": " << code << endl;
        return;
    }
    HuffmanCode(root->lchild, code + "0");
    HuffmanCode(root->rchild, code + "1");
}
```
