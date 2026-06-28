#include <iostream>
#include <vector>
using namespace std;

// 插入排序
bool cmp(int x, int y) {return x < y;}

// 1. 直接插入排序
void InsertSort(vector<int>& arr) {
    for(size_t i = 1; i < arr.size(); ++i) {
        int tmp = arr[i];
        int j = i - 1;
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

// 3. 快速排序
void QuickSort(vector<int>& arr, int low, int high) {
    if(low >= high) return;

    int pivot = arr[low];       // 选取第一个元素作为基准
    int i = low, j = high;      // 双指针扫描（避免污染原变量）

    while(i < j) {
        while(i < j && arr[j] >= pivot)
            j--;                // 从右向左扫描，找到第一个小于基准的元素
        
        if(i < j) arr[i++] = arr[j]; // 将小于基准的元素移动到左侧

        while(i < j && arr[i] <= pivot)
            i++;                // 从左向右扫描，找到第一个大于基准的元素

        if(i < j) arr[j--] = arr[i]; // 将大于基准的元素移动到右侧
    }
    arr[i] = pivot;            // 将基准元素放到最终剩下的位置

    QuickSort(arr, low, i - 1);   // 递归排序左子数组
    QuickSort(arr, i + 1, high);  // 递归排序右子数组
}

// 堆排序(以大根堆为例)
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

// 归并排序

// 基数排序