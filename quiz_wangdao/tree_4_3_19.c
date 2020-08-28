// 验证函数内部静态变量的递归

#include <stdio.h>

int wpl_order(int root, int deep) {
  static int res = 0;

  if (root > 0) {
    res += root * deep;

    wpl_order(root - 1, deep + 1);
  }

  return res;  // 静态变量需要返回，不然无法实现传递
}

int wpl(int root) {
  return wpl_order(root, 1);
}

int main(void) {
  printf("%d", wpl(5));
}