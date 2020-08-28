/**
 * 对单链表进行简单选择排序
 */

#include <iostream>

// 定义数据结构
typedef struct LinkNode {
  int data;
  struct LinkNode *next;
} LinkNode, *LinkList;

void creat_links(LinkList &L, int a[], int len) {
  L->next = NULL;
  for (int i = 0; i < len; i++) {
    LinkList p = (LinkList)malloc(sizeof(LinkNode));
    p->data = a[i];
    // 头插法
    p->next = L->next;
    L->next = p;
  }
}

void ouput_links(LinkList &L) {
  LinkNode *p = L->next;
  while (p) {
    std::cout << p->data << ",";
    p = p->next;
  }
  std::cout << std::endl;
}

void delete_links(LinkList &L) {
  LinkNode *p = L->next;
  while (p) {
    L->next = p->next;
    free(p);
    p = L->next;
  }
  free(L);
}

// 简单选择排序
void select_sort(LinkList &L) {
  LinkNode *p = L->next, *q, *min;
  while (p && p->next) {
    min = p;
    q = p->next;
    while (q) {
      if (q->data < min->data) {
        min = q;
      }
      q = q->next;
    }

    if (min != p) {
      int temp = min->data;
      min->data = p->data;
      p->data = temp;
    }

    p = p->next;
  }
}

int main(void) {
  LinkList L = (LinkList)malloc(sizeof(LinkNode));
  const int len = 5;
  int a[len] = {4, 12, 3, 8, 6};

  creat_links(L, a, len);
  ouput_links(L);

  select_sort(L);
  ouput_links(L);

  delete_links(L);

  return 0;
}
