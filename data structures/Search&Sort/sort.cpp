#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool cmp(int x, int y) {return x < y;}

// 插入排序
// 1. 直接插入排序
void InsertSort(vector<int>& arr) {
    for(size_t i = 1; i < arr.size(); ++i) {
        int tmp = arr[i]; // 待插入元素
        int j = i - 1; // 有序区的最后一个元素

        // 查找插入位置并移动元素
        while(j >= 0 && cmp(arr[j], tmp)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = tmp;
    }
}

// 2. 折半插入排序
void BinInsertSort(vector<int>& arr) {
    for(size_t i = 1; i < arr.size(); ++i) {

        if(!cmp(arr[i - 1], arr[i])) continue;

        int tmp = arr[i];
        int low = 0, high = i - 1;

        // upper_bound逻辑
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(cmp(tmp, arr[mid])) {
                high = mid - 1;         // 插入点在左半区
            } else { // 相等时继续向后查找
                low = mid + 1;          // 插入点在右半区
            }   
        }

        // 集中进行元素后移
        for(int j = i - 1; j >= high + 1; --j) 
            arr[j + 1] = arr[j];

        // 原R[i]插入到最终位置 arr[high + 1] 中
        arr[high + 1] = tmp;
    }
}

// 3. 希尔排序
void ShellSort(vector<int>& arr) {
    int d = arr.size() / 2; // 初始化增量

    while(d > 0) { // 最外层循环：控制增量收缩

        // 中层循环：从下标 d 开始，逐步向后扫描无序区
        for(size_t i = d; i < arr.size(); ++i) {
            int tmp = arr[i];
            int j = i - d;

            // 内层循环：同组内部进行插入平移
            while(j >= 0 && cmp(arr[j], tmp)) {
                arr[j + d] = arr[j];
                j -= d;
            }
            arr[j + d] = tmp;
        }
        d /= 2; // 收缩增量
    }
}

// 交换排序
// 1. 冒泡排序
void BubbleSort(vector<int>& arr) {
    for(size_t i = 0; i < arr.size() - 1; ++i) {
        bool swapped = false; // 标记本轮是否有交换发生
        for(size_t j = 0; j < arr.size() - 1 - i; ++j) {
            if(cmp(arr[j], arr[j + 1])) {
                swap(arr[j], arr[j + 1]);
                swapped = true; // 发生交换，标记为 true
            }
        }
        if(!swapped) break; // 如果本轮没有交换，说明已经有序 
    }
}

// 2. 双向冒泡排序
void CocktailSort(vector<int>& arr) {
    int left = 0, right = arr.size() - 1; // 初始化左右边界

    while(left < right) {
        bool swapped = false; // 标记本轮是否有交换发生

        // 从左向右冒泡
        for(int j = left; j < right; ++j) {
            if(cmp(arr[j], arr[j + 1])) {
                swap(arr[j], arr[j + 1]);
                swapped = true; // 发生交换，标记为 true
            }
        }
        --right; // 缩小右边界

        if(!swapped) break; // 如果本轮没有交换，说明已经有序 

        swapped = false; // 重置标记

        // 从右向左冒泡
        for(int j = right; j > left; --j) {
            if(cmp(arr[j - 1], arr[j])) {
                swap(arr[j - 1], arr[j]);
                swapped = true; // 发生交换，标记为 true
            }
        }
        ++left; // 缩小左边界

        if(!swapped) break; // 如果本轮没有交换，说明已经有序 
    }
}

// 3. 快速排序(挖坑法)
void QuickSort(vector<int>& arr, int low, int high) {
    if(low >= high) return;

    int pivot = arr[low];       // 选取第一个元素作为基准(初始的坑)
    int i = low, j = high;      // 双指针扫描（避免污染原变量）

    while(i < j) {
        while(i < j && arr[j] >= pivot)
            j--;                // 从右向左扫描，找到第一个小于基准的元素
        
        if(i < j) arr[i++] = arr[j]; // 将小于基准的元素移动到左侧(此时j变为坑)

        while(i < j && arr[i] <= pivot)
            i++;                // 从左向右扫描，找到第一个大于基准的元素

        if(i < j) arr[j--] = arr[i]; // 将大于基准的元素移动到右侧
    }
    arr[i] = pivot;            // 将基准元素放到最终剩下的位置

    QuickSort(arr, low, i - 1);   // 递归排序左子数组
    QuickSort(arr, i + 1, high);  // 递归排序右子数组
}

/*还可以用荷兰国旗算法优化*/

// 选择排序

// 1. 简单选择排序
void SelectSort(vector<int>& arr) {
    int n = arr.size();

    for(int i = 0; i < n - 1; ++i) {
        int minIndex = i; // 假设当前元素为最小值的索引

        // 在 a[i...n-1] 中找最小元素
        for(int j = i + 1; j < n; ++j) {
            if(cmp(arr[minIndex], arr[j])) 
                minIndex = j; // 更新最小值索引
        }

        // 将最小元素放到当前有序区末尾
        if(minIndex != i)
            swap(arr[i], arr[minIndex]);

    }
}

// 2. 堆排序(以大根堆为例)
void heapify(vector<int>& arr, int n, int i) {
    int largest = i; // 初始化最大元素为根节点
    int left = 2 * i + 1; // 左子节点索引(0-based)
    int right = 2 * i + 2; // 右子节点索引

    // 比较左子节点
    if(left < n && cmp(arr[largest], arr[left])) {
        largest = left;
    }
    // 比较右子节点
    if(right < n && cmp(arr[largest], arr[right])) {
        largest = right;
    }

    // 如果最大元素不是根节点，则交换并继续调整
    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void HeapSort(vector<int>& arr) {
    int n = arr.size();

    // 构建大根堆
    // 从最后一个非叶子节点开始，逐个调整堆
    for(int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }

    // 逐个将最大元素移到末尾，并调整堆
    for(int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]); // 将当前最大元素移到末尾
        heapify(arr, i, 0);   // 调整剩余的堆
    }
}

/*heapify(arr, n, i) 函数的作用是下滤调整，
只有当节点 i 的左、右子树都已经是一个合格的堆时，调用它才能把以 i 为根的整棵树调整为堆。
不能直接对完全无序的数组进行调整。*/

// (二路)归并排序
void Merge(vector<int>& arr, vector<int>& temp,
    int left, int mid, int right) {

    int i = left;      // 左子数组的起始索引
    int j = mid + 1;   // 右子数组的起始索引
    int k = left;      // 临时数组的起始索引

    // 合并两个子数组
    while(i <= mid && j <= right) {
        if(cmp(arr[i], arr[j]))
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i <= mid) // 复制左子数组的剩余元素
        temp[k++] = arr[i++];
    while(j <= right) // 复制右子数组的剩余元素
        temp[k++] = arr[j++];

    for(int l = left; l <= right; ++l) // 将临时数组的元素复制回原数组
        arr[l] = temp[l];
}

// 递归实现
void _MergeSort(vector<int>& arr, vector<int>& temp, int left, int right) {
    if(left >= right) return;

    int mid = left + (right - left) / 2; // 防止溢出
    _MergeSort(arr, temp, left, mid);     // 排序左半部分
    _MergeSort(arr, temp, mid + 1, right); // 排序右半部分
    Merge(arr, temp, left, mid, right);   // 合并两个有序子数组
}
void MergeSort(vector<int>& arr) {
    vector<int> temp(arr.size()); // 临时数组
    _MergeSort(arr, temp, 0, arr.size() - 1); // 左右都是闭区间
}

// 迭代实现
void MergeSortIt(vector<int>& arr) {
    int n = arr.size();
    vector<int> temp(n);

    // 外层循环：控制待合并有序段宽度
    for(int w = 1; w < n; w *= 2) {

        // 每次合并两个相邻的有序段
        for(int left = 0; left < n; left += 2 * w) {
            int mid = min(left + w - 1, n - 1); // 左半段的结束索引
            int right = min(left + 2 * w - 1, n - 1); // 右半段的结束索引

            if(mid < right) // 如果右半段存在
                Merge(arr, temp, left, mid, right);
        }
    }
}

// 基数排序(LSD)
void RadixSort(vector<int>& arr) {
    int n = arr.size();
    if(n <= 1) return;

    // 找到最大值以确定位数
    int maxVal = arr[0];
    for(int i = 1; i < n; ++i) {
        if(cmp(maxVal, arr[i]))
            maxVal = arr[i];
    }

    queue<int> buckets[10]; // 10个桶，分别对应0-9

    // 从个位开始，对每一位进行计数排序
    for(int exp = 1; maxVal / exp > 0; exp *= 10) {
        
        // 将元素放入对应的桶中
        for(int i = 0; i < n; ++i) {
            int digit = (arr[i] / exp) % 10;
            buckets[digit].push(arr[i]);
        }

        // 从桶中取出元素，按顺序放回原数组
        int index = 0;
        for(int i = 0; i < 10; ++i) {
            while(!buckets[i].empty()) {
                arr[index++] = buckets[i].front();
                buckets[i].pop();
            }
        }
    }
}

// 计数排序
void CountingSort(vector<int>& arr) {

    // 寻找最值，确定统计范围
    int maxVal = arr[0], minVal = arr[0];
    for(int x : arr) {
        if(x > maxVal) maxVal = x;
        if(x < minVal) minVal = x;
    }
    int range = maxVal - minVal + 1;

    // 统计每个元素的出现次数
    vector<int> count(range, 0);
    for(int x : arr)
        count[x - minVal]++; // 把 x 映射到从 0 开始的索引
    
    // 计算前缀和，确定元素最终位置
    for(int i = 0; i < range; ++i)
        count[i] += count[i - 1];

    // 倒序遍历原数组，确保排序稳定性
    vector<int> temp(arr.size());
    for(int i = arr.size() - 1; i >= 0; --i) {
        int val = arr[i];
        int pos = count[val - minVal] - 1; // 对应的下标
        temp[pos] = val;
        count[val - minVal]--;
    }

    arr = temp;
}