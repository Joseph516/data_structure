#ifndef _BITREE_H_
#define _BITREE_H_

typedef char TElemType;

typedef struct BiTNode {
  TElemType data;
  struct BiTNode *lchild, *rchild;

} BiTNode, *BiTree;


enum PointerTag{Link, Thread};
typedef struct BiThrNode {
  TElemType data;
  struct BiThrNode *lchild, *rchild;
  int ltag, rtag;
} BiThrNode, *BiThrTree;

#endif