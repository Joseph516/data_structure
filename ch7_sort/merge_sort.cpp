// 归并排序

#include <iostream>


// 合并操作，B为辅助数组
void Merge(int A[], int B[], int low, int mid, int high) {
  for (int k = low; k <= high; ++k) {
    B[k] = A[k];
  }

  int i = low, j = mid + 1, k = i;
  while (i <= mid && j <= high) {
    if (B[i] < B[j]) {
      A[k++] = B[i++];
    } else {
      A[k++] = B[j++];
    }
  }

  while (i <= mid) {
    A[k++] = B[i++];
  }
  while (j <= high) {
    A[k++] = B[j++];
  }
}

// 递归形式的归并排序
// 在数组下标low和high之间排序
void MergeSort(int A[], int B[], int low, int high) {
  if (low < high) {
    int mid = (low + high) / 2;
    MergeSort(A, B, low, mid);
    MergeSort(A, B, mid + 1, high);
    Merge(A, B, low, mid, high);
  }
}

int main(void) {
  const int n = 8;
  int A[n] = {100, 5, 7, 4, 2, 1, 0, -3};
  int B[n];

  MergeSort(A, B, 0, n-1);
  for (int i = 0; i < n; ++i) {
    std::cout << A[i] << ",";
  }
}