// 交换排序，包括冒泡排序与快速排序

#include <iostream>

// 冒泡排序
// 从大到小顺序排列
void BubbleSort(int A[], int n) {
  int i, j;
  bool change = true;  // 交换标志位

  for (i = n - 1; i >= 0 && change; --i) {
    change = false;
    for (j = 0; j < i; ++j) {
      if (A[j + 1] < A[j]) {
        std::swap(A[j], A[j + 1]);
        change = true;
      }
    }
  }
}

// 快速排序
// 快速排序划分
int Partition(int A[], int low, int high) {
  int pivot = A[low];  // 中枢点，划分表

  while (low < high) {
    while (low < high && A[high] >= pivot) {
      --high;
    }
    A[low] = A[high];
    while (low < high && A[low] <= pivot) {
      ++low;
    }
    A[high] = A[low];
  }
  A[low] = pivot;
  return low;
}

// 从小到大逆序
void QuickSort(int A[], int low, int high) {
  if (low < high) {
    int pivot_pos = Partition(A, low, high);
    QuickSort(A, low, pivot_pos - 1);
    QuickSort(A, pivot_pos + 1, high);
  }
}

int main(void) {
  const int n = 8;
  int A[n] = {8, 7, 6, 5, 4, 3, 2, 1};
  //   BubbleSort(A, n);
  QuickSort(A, 0, n - 1);
  for (int i = 0; i < n; ++i) {
    std::cout << A[i] << ",";
  }
}