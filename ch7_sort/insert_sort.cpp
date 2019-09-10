#include <iostream>

// 直接插入排序
// 首位只作为哨兵，不参与排序
// A：待排序数组， n为数组长度
void InsertSort(int A[], int n) {
  int i, j;
  for (i = 2; i < n; ++i) {
    if (A[i] < A[i - 1]) {
      A[0] = A[i];
      for (j = i - 1; A[j] > A[0]; j--) {
        A[j + 1] = A[j];
      }

      A[j + 1] = A[0];
    }
  }
}

// 折半插入排序
// 采用折半（二分）查找定位元素，移动元素同直接插入排序
void HalfInsertSort(int A[], int n) {
  int i, j;
  for (i = 2; i < n; ++i) {
    if (A[i] < A[i - 1]) {
      A[0] = A[i]; // 暂时保存，非哨兵
      // 折半查找
      // high指示最后一个不大于A[0]的数，目标位置插入位于high+1
      int low = 1, high = i - 1, mid;
      while (low <= high) {
        mid = (low + high) / 2;
        if (A[mid] > A[0]) {
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      }

      // 移动元素
      for (j = i - 1; j >= high + 1; --j) {
        A[j + 1] = A[j];
      }
      A[high + 1] = A[0];
    }
  }
}

// 希尔排序
void ShellSort(int A[], int n) {
  // A[0]不在是哨兵
  // 前后记录增量是dk
  int dk, i, j;
  for (dk = n / 2; dk >= 1; dk /= 2) {
    // 每趟希尔排序，相当于一次简单插入排序
    // 只是各个元素的间隔是dk
    for (i = dk + 1; i < n; ++i) {
      if (A[i] < A[i - dk]) {
        A[0] = A[i];  // 暂时保存待插入元素
        for (j = i - dk; j > 0 && A[j] > A[0]; j -= dk) {
          A[j + dk] = A[j];
        }

        A[j + dk] = A[0];
      }
    }
  }
}

int main(void) {
  const int n = 8;
  int A[n] = {-100, 5, 7, 4, 2, 1, 0, -3};
  // InsertSort(A, n);
  // HalfInsertSort(A, n);
  ShellSort(A, n);
  for (int i = 1; i < n; ++i) {
    std::cout << A[i] << ",";
  }
}