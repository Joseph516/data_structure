// 选择排序

#include <iostream>

// 简单选择排序
// 顺序输出
void SimpleSelectSort(int A[], int n) {
  int i, j, min;
  for (i = 0; i < n; ++i) {
    min = i;
    for (j = i + 1; j < n; ++j) {
      if (A[j] < A[i]) {
        std::swap(j, min);
      }
    }
    if (min != i) {
      std::swap(A[i], A[min]);
    }
  }
}

/** 堆排序方法
 * 对数组A中的1~n进行排序, 0位不进行排序(考虑树结构的特殊性)
 */

/**
 * Detail: 向下调整方法，得到大顶堆
 * Params: A:待调整数组， k：调整节点，n：堆元素数目
 * Return：NULL
 */
void AdjustDown(int A[], int k, int n) {
  A[0] = A[k];  // 暂时保存
  for (int i = 2 * k; i <= n; i *= 2) {
    if (i + 1 <= n && A[i + 1] > A[i]) {
      ++i;  // 选出较大的孩子
    }
    if (A[0] >= A[i]) {
      break;  // 孩子节点已经小于当前顶点，不用向下调整
    } else {
      A[k] = A[i];  // 向下调整
      k = i;
    }
  }
  A[k] = A[0];  // 最终位置
}

/**
 * Detail: 向上调整方法，得到大顶堆
 * Params: A:待调整数组， k：调整节点，n：堆元素数目
 * Return：NULL
 */
void AdjustUp(int A[], int k, int n) {
  A[0] = A[k];  // 暂时保存
  for (int i = k / 2; i > 0; i /= 2) {
    if (A[i] < A[0]) {
      A[k] = A[i];  // 当前节点值大于双亲节点，向上调整
      k = i;
    }
  }
  A[k] = A[0];
}

// 建立大顶堆
void BuildMaxHeap(int A[], int n) {
  for (int i = n / 2; i >= 1; --i) {
    AdjustDown(A, i, n);
  }
}

// 堆排序
void HeapSort(int A[], int n) {
  BuildMaxHeap(A, n);

  for (int i = n; i > 1; --i) {
    std::swap(A[i], A[1]);    // 输出堆顶
    AdjustDown(A, 1, i - 1);  // 针对堆顶在剩下的元素中调整
  }
}


int main(void) {
  const int n = 8;
  int A[n] = {8, 7, 6, 5, 4, 3, 2, 1};
  //   SimpleSelectSort(A, n);
  HeapSort(A, n - 1);
  for (int i = 0; i < n; ++i) {
    std::cout << A[i] << ",";
  }
}