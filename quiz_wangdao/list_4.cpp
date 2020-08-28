#include <iostream>

// 删除数组中介于s于t之间的数字
void DelValue(int a[], int n, int s, int t) {
  int k = 0, i;
  for (i = 0; i < n; i++) {
    while (a[i] >= s && a[i] <= t) {
      ++i;
    }
    if (i < n) {
      a[k] = a[i];
      ++k;
    }
  }

  for (int j = 0; j < k; j++) {
    std::cout << a[j] << ",";
  }
}

int main(void) {
  int a[10] = {1, 2, 10, 4, 5, 6, 7, 3, 9, 8};

  DelValue(a, 10, 5, 7);
  return 0;
}