/**
 *  递归转非递归算法
 *  动态回归
 */
#include <stdlib.h>
#include <iostream>

float ComputePn(const int n, const float x) {
  if (n == 0) {
    return 1;
  }
  if (n == 1) {
    return 2 * x;
  }

  // 采用动态回归办法，也是栈实现方法
  float* s = (float*)malloc(sizeof(float) * n);
  for (int i = 0; i < n; ++i) {
    s[i] = 0;
  }

  float fv0 = 1, fv1 = 2 * x;
  for (int i = 2; i <= n; ++i) {
    s[i] = 2 * x * fv1 - 2 * (i - 1) * fv0;
    fv0 = fv1;
    fv1 = s[i];
  }

  free(s);
  s = NULL;

  return fv1;
}

int main(void) {
  std::cout << ComputePn(2, 0) << std::endl;
  return 0;
}