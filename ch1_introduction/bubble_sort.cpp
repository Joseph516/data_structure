#define FALSE 0;
#define TRUE 1;

#include <iostream>

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void bubbleSort(int a[], int n) {
  // 将 a 中整数序列重新排列成自小至大有序的整数序列。
  for (int i = n - 1, change; i > 1 && change; --i) {
    // bubble sort
    change = FALSE;  // change 为元素进行交换标志
    for (int j = 0; j < i; ++j) {
      if (a[j] > a[j + 1]) {
        swap(a[j], a[j + 1]);
        change = TRUE;
      }
    }  // 一趟冒泡
  }
}

int main(void) {
#ifdef DEBUG
  // g++ -o debug -DDEBUG bubble_sort.cpp

  int a[5] = {1, 5, 6, 6, 2};
  bubbleSort(a, 5);

  for (int i = 0; i < 5; i++) {
    std::cout << a[i] << ",";
  }
#endif

  return 0;
}
