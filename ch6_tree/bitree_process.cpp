#include "bitree_process.h"

BiTreeProcess::BiTreeProcess() {
  std::cout << "Please input nodes, '^' means null: ";
  creatBiTree(bi_tree_);
}

BiTreeProcess ::~BiTreeProcess() {
  clearBiTree(bi_tree_);
  if (bi_tree_) {
    delete bi_tree_;
    bi_tree_ = NULL;
  }
}

void BiTreeProcess::creatBiTree(BiTree &T) {
  char ch;
  std::cin >> ch;

  if (ch == '^') {
    T = NULL;
  } else {
    T = new BiTNode;
    T->data = ch;
    creatBiTree(T->lchild);
    creatBiTree(T->rchild);
  }
  return;
}

void BiTreeProcess::clearBiTree(BiTree &T) {
  if (T == NULL) {
    return;
  }

  if (T->lchild || T->rchild) {
    clearBiTree(T->lchild);
    clearBiTree(T->rchild);
  } else {
    // T->data = 0;
    delete T;
    T = NULL;
  }
}

void BiTreeProcess::preOrderTraverse(BiTree &T) {
  if (T) {
    std::cout << T->data << " ";
    preOrderTraverse(T->lchild);
    preOrderTraverse(T->rchild);
  }
}

void BiTreeProcess::inOrderTraverse(BiTree &T) {
  if (T) {
    inOrderTraverse(T->lchild);
    std::cout << T->data << " ";
    inOrderTraverse(T->rchild);
  }
}

void BiTreeProcess::postOrderTraverse(BiTree &T) {
  if (T) {
    postOrderTraverse(T->lchild);
    postOrderTraverse(T->rchild);
    std::cout << T->data << " ";
  }
}

void BiTreeProcess::preOrderNonRecursion() {
  std::stack<BiTree> s;
  BiTree T = bi_tree_;  // 工作指针

  while (T || !s.empty()) {
    if (T) {
      s.push(T);
      std::cout << T->data << " ";  // 加入stack时访问
      T = T->lchild;                // 搜索至最左结点
    } else {
      T = s.top();
      s.pop();
      T = T->rchild;  // 结点无左孩子，开始搜索右孩子
    }
  }
}

void BiTreeProcess::inOrderNonRecursion() {
  std::stack<BiTree> s;
  BiTree T = bi_tree_;  // 工作指针

  while (T || !s.empty()) {
    if (T) {
      s.push(T);
      T = T->lchild;  // 搜索至最左结点
    } else {
      // visit
      T = s.top();
      s.pop();
      std::cout << T->data << " ";

      T = T->rchild;  // 结点无左孩子，开始搜索右孩子
    }
  }
}

void BiTreeProcess::postOrderNonRecursion() {
  std::stack<BiTree> s;
  BiTree T = bi_tree_;  // 工作指针
  BiTree r = NULL;      // 记录已经访问过的指针

  while (T || !s.empty()) {
    if (T) {
      s.push(T);
      T = T->lchild;  // 搜索至最左结点
    } else {
      T = s.top();

      if (T->rchild && T->rchild != r) {
        T = T->rchild;  // 结点无左孩子，开始搜索未被访问的右孩子
      } else {
        s.pop();
        std::cout << T->data << " ";
        r = T;
        T = NULL;  // 防止重复入栈
      }
    }
  }
}