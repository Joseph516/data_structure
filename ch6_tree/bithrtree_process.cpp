#include <cstdlib>
#include "bitree.h"

void InThread(BiThrTree &p, BiThrTree &pre) {
  if (p != NULL) {
    InThread(p, pre);
    if (p->lchild == NULL) {
      p->lchild = pre;
      p->ltag = PointerTag::Thread;
    }

    if (pre != NULL && pre->rchild != NULL) {
      pre->rchild = p;
      pre->rtag = PointerTag::Thread;
    }

    pre = p;

    InThread(p->rchild, pre);
  }
}

void CreatInThreadTree(BiThrTree T) {
  BiThrTree pre = NULL;
  if (T != NULL) {
    InThread(T, pre);
    pre->rchild = NULL;
    pre->rtag = PointerTag::Thread;
  }
}