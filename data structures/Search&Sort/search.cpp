#include <iostream>
#include <vector>
using namespace std;

// 线性表

// 1. 顺序查找
int SeqSearch1(const vector<int>& arr, int key) {
    for(size_t i = 0; i < arr.size(); ++i) {
        if(arr[i] == key) {
            return i; // 返回找到的元素的索引
        }
    }
    return -1; // 返回-1表示未找到
}

int SeqSearch2(const vector<int>& arr, int key) {
    int n = arr.size();
    vector<int> R = arr;
    R.push_back(key); // 将key放在数组末尾作为哨兵

    int i = 0;
    while(R[i] != key) {
        i++;
    }
    if(i < n) return i;
    else return -1;
}

// 2. 二分查找（前提：数据有序）
int BinSearch1(const vector<int>& arr, int key) {
    int low = 0, high = arr.size() - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2; // 防止溢出
        if(arr[mid] == key) {
            return mid; // 返回找到的元素的索引
        } else if(arr[mid] < key) {
            low = mid + 1; // 在右半部分继续查找
        } else {
            high = mid - 1; // 在左半部分继续查找
        }
    }
    return -1; // 返回-1表示未找到
}

int BinSearch2(const vector<int>& arr, int low, int high, int key) {
    if(low > high) return -1; // 基本情况：未找到

    int mid = low + (high - low) / 2;
    if(arr[mid] == key) return mid;
    else if(arr[mid] < key)
        return BinSearch2(arr, mid + 1, high, key);
    else
        return BinSearch2(arr, low, mid - 1, key);
}

// 3. 分块查找（块间有序，块内无序）
struct Index {
    int key; // 块的最大值
    int link; // 块的起始位置
};
int BlkSearch(const vector<Index>& indexArr, const vector<int>& arr, int s, int key) {
    int b = indexArr.size(), n = arr.size();
    
    // ====== 第一级：在索引表中二分查找定位块 ======
    int low = 0, high = b - 1;
    int block_idx = -1;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(indexArr[mid].key >= key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if(low < b) block_idx = low; // 定位到块
    else return -1; // 没有找到合适的块

    // ====== 第二级：在块内顺序查找 ======
    int start = indexArr[block_idx].link;
    int end = (block_idx == b - 1) ? arr.size() : start + s; // 块的结束位置

    for(int i = start; i < end; ++i)
        if(arr[i] == key) return i; // 返回找到的元素的索引

    return -1; // 返回-1表示未找到
}

//树表

// 1. 二叉排序树（BST）
struct BSTNode {
    int key;
    BSTNode* lchild, *rchild;

    BSTNode(int val) : key(val), lchild(nullptr), rchild(nullptr) {}
};

BSTNode* _SearchBST(BSTNode* root, int key) {
    if(!root || root -> key == key) return root;

    if(key < root -> key) return _SearchBST(root -> lchild, key);
    else return _SearchBST(root -> rchild, key);
}

BSTNode* _InsertBST(BSTNode* root, int key) {
    if(!root) return new BSTNode(key);

    if(key < root -> key) {
        root -> lchild = _InsertBST(root -> lchild, key);
    } else if(key > root -> key) {
        root -> rchild = _InsertBST(root -> rchild, key);
    }
    return root;
}
BSTNode* CreateBST(const vector<int>& arr) {
    BSTNode* root = nullptr;
    for(int key : arr) {
        root = _InsertBST(root, key);
    }
    return root;
}

bool DeleteBST(BSTNode* &root, int key) {
    // 1. 寻路边界：没找到
    if (root == nullptr) return false; 

    // 2. 寻路路由阶段
    if (key < root -> key) {
        return DeleteBST(root -> lchild, key); // 递归向左找
    } 
    else if (key > root -> key) {
        return DeleteBST(root -> rchild, key); // 递归向右找
    } 
    
    // 3. 命中目标阶段 (key == root -> key)，原地展开物理拆卸
    BSTNode* temp = root; 

    // 【形态1】无右子树
    if (root -> rchild == nullptr) {
        root = root -> lchild; 
        delete temp;
    } 

    // 【形态2】无左子树
    else if (root -> lchild == nullptr) {
        root = root -> rchild; 
        delete temp;
    } 

    // 【形态3】双支节点（前驱替代法）
    else {
        BSTNode* q = root->lchild;
        while (q->rchild != nullptr) {
            q = q->rchild; // 向右探底找前驱
        }
        root->key = q->key;// 值覆盖
        
        // 删除前驱
        DeleteBST(root->lchild, q->key); 
    }
    
    return true;
}
// 2. AVL树
struct AVLNode {
    int key;
    string data;
    AVLNode* lchild, *rchild;
    int height; // 结点高度

    AVLNode(int val, const string& str)
        : key(val), data(str), lchild(nullptr), rchild(nullptr), height(1) {}
};

int GetHeight(AVLNode* node) {
    return node ? node -> height : 0;
}

int GetBalanceFactor(AVLNode* node) {
    return node ? GetHeight(node -> lchild) - GetHeight(node -> rchild) : 0;
}

void RightRotate(AVLNode*& p) {
    AVLNode* newRoot = p -> lchild; // 新根是原根的左子树

    p -> lchild = newRoot -> rchild; // 冲突的右子树接到原根的左子树
    newRoot -> rchild = p; // 原根成为新根的右子树

    p -> height = 1 + max(GetHeight(p -> lchild), 
        GetHeight(p -> rchild));
    newRoot -> height = 1 + max(GetHeight(newRoot -> lchild), 
        GetHeight(newRoot -> rchild));

    p = newRoot; // 更新根指针
}

void LeftRotate(AVLNode*& p) {
    AVLNode* newRoot = p -> rchild; // 新根是原根的右子树

    p -> rchild = newRoot -> lchild; // 冲突的左子树接到原跟的右子树
    newRoot -> lchild = p; // 原根成为新根的左子树

    p -> height = 1 + max(GetHeight(p -> lchild),
        GetHeight(p -> rchild));
    newRoot -> height = 1 + max(GetHeight(newRoot -> lchild),
        GetHeight(newRoot -> rchild));

    p = newRoot; // 更新根指针
}

void InsertAVL(AVLNode*& root, int key, const string& data) {
    if(!root) {
        root = new AVLNode(key, data);
        return;
    }

    int oldHeight = root -> height;

    if(key < root -> key) {
        InsertAVL(root -> lchild, key, data);
    } else if(key > root -> key) {
        InsertAVL(root -> rchild, key, data);
    } else {
        root -> data = data; // 更新数据
        return;
    }

    // ==================== 回溯过程 ====================
    
    // 1. 刷新当前节点在历经底层变动后的最新几何树高
    root -> height = 1 + max(GetHeight(root -> lchild), 
        GetHeight(root -> rchild));

    // 2. 检测高度差是否超标（AVL树的平衡条件）
    if(root -> height == oldHeight) return; // 没有变高，不需要调整

    int bf = GetBalanceFactor(root);

    // 3. 根据失衡类型进行旋转调整（2层失衡）
    if(bf > 1) { // 左子树过高(BF = 2)
        if(GetBalanceFactor(root -> lchild) >= 0) { // 检查左支的左子树
            // LL失衡：右旋
            RightRotate(root);
        } else { // 检查左支的右子树
            // LR失衡：先左旋再右旋
            LeftRotate(root -> lchild);
            RightRotate(root);
        }
    } else if(bf < -1) { // 右子树过高(BF = -2)
        if(GetBalanceFactor(root -> rchild) <= 0) { // 检查右支的右子树
            // RR失衡：左旋
            LeftRotate(root);
        } else { // 检查右支的左子树
            // RL失衡：先右旋再左旋
            RightRotate(root -> rchild);
            LeftRotate(root);
        }
    }
}
void CreateAVL(AVLNode*& root, const vector<pair<int, string>>& arr) {
    for(const auto& p : arr) {
        InsertAVL(root, p.first, p.second);
    }
}
// 3. 红黑树
// 懒得看了今天
// 4. B树
// 5. B+树

// 哈希表
const int NULLKEY = -1;
const int DELETED = -1;

struct HNode1 {
    int key;
    string data;

    HNode1() : key(NULLKEY), data("") {}
    HNode1(int k, const string& d) : key(k), data(d) {}
};

class HashTable1 {
private:
    vector<HNode1> table;
    int size;
    int p; // 用于除留余数法的质数

public:
    HashTable1(int n) : size(n), table(n) {
        // 选择一个小于n的质数作为p
        p = n - 1;
        while(p > 1) {
            bool isPrime = true;
            for(int i = 2; i <= p / 2; ++i) {
                if(p % i == 0) {
                    isPrime = false;
                    break;
                }
            }
            if(isPrime) break;
            --p;
        }

        for(int i = 0; i < size; ++i) {
            table[i] = HNode1(); // 初始化哈希表
        }
    }

    int Search(int k) {
        int d = k % p;

        while(table[d].key != NULLKEY) {
            if(table[d].key == k) {
                return d; // 找到键，返回索引
            }
            d = (d + 1) % size; // 线性探测下一个位置
        }

        /*平方探测法实现
        int start_d = d; // 记录初始位置以避免死循环
        int i = 1;

        while(table[d].key != NULLKEY) {
            if(table[d].key == k) return d;
            if(i * i >= size) break; // 探测次数超过表大小，停止探测

            int k_val = (i + 1) / 2; // 计算平方探测的偏移量
            int offset = k_val * k_val;

            if(i % 2 == 1) {
                d = (start_d + offset) % size; // 奇数次探测向右
            } else {
                d = (start_d - (offset % size) + size) % size; // 偶数次探测向左
            }
            i++;
        }*/

        return -1;
    }

    bool Insert(int k, const string& v) {
        if(Search(k) != -1) return false; // 键已存在

        int d = k % p;
        while(table[d].key != NULLKEY && table[d].key != DELETED) {
            d = (d + 1) % size; // 线性探测下一个位置
        }
        table[d] = HNode1(k, v); // 插入新节点
        return true;
    }

    bool Delete(int k) {
        int d = Search(k);
        if(d == -1) return false;

        table[d].key = DELETED;
        table[d].data = "";
        return true;
    }
};

struct HNode2 {
    int key;
    string data;
    HNode2* next;

    HNode2() : key(NULLKEY), data(""), next(nullptr) {}
    HNode2(int k, const string& d) : key(k), data(d), next(nullptr) {}
};

class HashTable2 {
private:
    vector<HNode2*> table;
    int size;
    int p;

public:
    HashTable2(int n, int prime) : size(n), p(prime), table(n, nullptr) {}

    ~HashTable2() {
        for(int i = 0; i < size; ++i) {
            HNode2* curr = table[i];
            while(curr) {
                HNode2* nxt = curr -> next;
                delete curr;
                curr = nxt;
            }
        }
    }

    HNode2* Search(int k) {
        int d = k % p;
        HNode2* curr = table[d];

        while(curr) {
            if(curr -> key == k) {
                return curr;
            }
            curr = curr -> next;
        }

        return nullptr;
    }

    bool Insert(int k, const string& v) {
        if(Search(k)) return false;

        int d = k % p;
        HNode2* newNode = new HNode2(k, v);
        newNode -> next = table[d];
        table[d] = newNode;
        return true;
    }

    bool Delete(int k) {
        int d = k % p;
        HNode2* curr = table[d];
        if(!curr) return false;
        
        if(curr -> key == k) {
            table[d] = curr -> next;
            delete curr;
            return true;
        }

        HNode2* prev = curr;
        curr = curr -> next;

        while(curr) {
            if(curr -> key == k) {
                prev -> next = curr -> next;
                delete curr;
                return true;
            }
            prev = curr;
            curr = curr -> next;
        }

        return false;
    }
};