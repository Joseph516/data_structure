/**
 * 搜索数组中第k小的数
 */

#include <iostream>

// method1: quick_sort, T(n)=O(n)
// quick_sort partition
template <typename T>
int partition(T a[], int low, int high) {
  int pivot = a[low];
  while (low < high) {
    while (low < high && a[high] >= pivot) {
      --high;
    }
    a[low] = a[high];
    while (low < high && a[low] <= pivot) {
      ++low;
    }
    a[high] = a[low];
  }
  a[low] = pivot;
  //   for (int i = 0; i < 9; i++) {
  //     std::cout << a[i] << ";";
  //   }
  //   std::cout << std::endl;
  return low;
}

// 搜索数组中第k小的数
template <typename T>
T k_elem(T a[], int low, int high, int k) {
  // quick_sort partition
  int pivot_pos = partition(a, low, high);

  if (pivot_pos == k - 1) {
    return a[pivot_pos];
  } else if (pivot_pos > k - 1) {
    return k_elem(a, low, pivot_pos - 1, k);
  } else {
    // return k_elem(a, pivot_pos + 1, high, pivot_pos - k);
    return k_elem(a, pivot_pos + 1, high, k);
  }
}

// method2: Heap Adjust, T(n)=O(klogn)
// Output the top of Min Heap for k times, then you will get the result.

// test
int main(void) {
  int a[10] = {2, 3, 8, 5, 1, 6, 7, 4, 9};
  std::cout << k_elem(a, 0, 8, 5);
}
