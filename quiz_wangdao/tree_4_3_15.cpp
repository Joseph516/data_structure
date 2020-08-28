// 递归实现满二叉树前序序列转后序序列

#include <iostream>

void PreToPost(char pre[], int l1, int h1, char post[], int l2, int h2) {
  if (h1 >= l1) {
      int half = (h1 - l1) / 2;
      post[h2] = pre[l1];
      PreToPost(pre, l1+1, l1+half, post, l2, l2+half-1);
      PreToPost(pre, l1+half+1, h1, post, l2+half, h2-1);
  }
}


int main(void) {
  char pre[] = "ABDECFG";
  char post[7];

  PreToPost(pre, 0, 6, post, 0, 6);

  for (int i = 0; i <= 6; i++) {
    std::cout << post[i] << ",";
  }

  return 0;
}