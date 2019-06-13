#ifndef _BITREE_H_
#define _BITREE_H_

typedef char TElemType;

typedef struct BiTNode {
  TElemType data;
  struct BiTNode *lchild, *rchild;

} BiTNode, *BiTree;

#endif