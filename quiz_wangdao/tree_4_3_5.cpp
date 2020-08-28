#include "../ch6_tree/bitree_process.cpp"

// 递归计算二叉树的高度
// 非递归方法可以用层序遍历实现
int CalcDepth(BiTree T) {
  if (T == NULL) {
    return 0;  //
  } else {
    int left = 1, right = 1;
    if (T->lchild) {
      left = CalcDepth(T->lchild) + 1;
    }

    if (T->rchild) {
      right = CalcDepth(T->rchild) + 1;
    }

    return left > right ? left : right;
  }
}