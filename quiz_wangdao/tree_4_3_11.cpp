#include "../ch6_tree/bitree_process.cpp"

// 查找二叉树满足一定值的结点，并将其与其节点一起删除。
void DeleteElem(BiTree& T) {
  if (T) {
    DeleteElem(T->lchild);
    DeleteElem(T->rchild);
    free(T);
    T = NULL;
  }
}
void FindElem(BiTree& T, char x) {
  if (T == NULL) {
    return;
  } else if (T->data == x) {
    DeleteElem(T);
  } else {
    FindElem(T->lchild, x);
    FindElem(T->rchild, x);
  }
}

int main(void) {
  // 创建二叉树：
  // for example:abc^^de^g^^f^^^
  // for example:-+a^^*b^^-c^^d^^/e^^f^^
  BiTreeProcess bi;

  // 二叉树递归遍历测试
  std::cout << "preOrderTraverse result: ";
  bi.preOrderTraverse(bi.getRoof());
  std::cout << std::endl;

  FindElem(bi.getRoof(), '+');

  std::cout << "preOrderTraverse result: ";
  bi.preOrderTraverse(bi.getRoof());
  std::cout << std::endl;
  // input: -+a^^*b^^-c^^d^^/e^^f^^
  // output: - / e f

  return 0;
}