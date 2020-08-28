#ifndef _BITREE_PROCESS_H_
#define _BITREE_PROCESS_H_

#include <iostream>
#include <stack>
#include "bitree.h"


class BiTreeProcess {
  private:
  BiTree bi_tree_;  // 二叉树的根结点

  public:
  BiTreeProcess();
  ~BiTreeProcess();

  // 构建二叉树
  // 按照先序次序输入二叉树中结点的值（字符），空格字符表示空树。
  void creatBiTree(BiTree &T);

  // 移除二叉树，释放空间
  void clearBiTree(BiTree &T);

  BiTree &getRoof() {
    return bi_tree_;
  }

  // 递归先序遍历二叉树  
  void preOrderTraverse(BiTree &T);
  // 非递归先序遍历二叉树  
  void preOrderNonRecursion();

  // 递归中序遍历二叉树
  void inOrderTraverse(BiTree &T);
  // 非递归中序遍历二叉树  
  void inOrderNonRecursion();

  // 递归后序遍历二叉树
  void postOrderTraverse(BiTree &T);
  // 非递归后序遍历二叉树
  void postOrderNonRecursion();
};

#endif