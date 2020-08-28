/**
 * 中南大学2019年考研试题
 * 题目: 求集合A=AU(B-C)，集合用单链表表示
 */

#include <iostream>

typedef struct LNode {
  int data;
  struct LNode *next;
} LNode, *LinkList;

void Merge(LinkList &la, LinkList lb, LinkList lc) {
  LinkList pa, pb, pc, p;
  pb = lb->next;
  while (pb) {
    pc = lc->next;
    while (pc && pc->data != pb->data) {
      pc = pc->next;
    }
    if (pc == NULL) {
      pa = la->next;
      while (pa && pa->data != pb->data) {
        pa = pa->next;
      }
      if (pa == NULL) {
        p = (LinkList)malloc(sizeof(LNode));
        p->data = pb->data;
        p->next = la->next;
        la->next = p;
      }
    }
    pb = pb->next;
  }
}

void CreatLink(LinkList &link) {
  int len;
  std::cout << "\nInput length of link: ";
  std::cin >> len;
  int i = 0;
  link = (LinkList)malloc(sizeof(LNode));
  link->next = NULL;
  LinkList p;
  while (i < len) {
    if (!(p = (LinkList)malloc(sizeof(LNode)))) {
      exit(1);
    }
    std::cout << "Input elements of link:";
    std::cin >> p->data;
    p->next = link->next;
    link->next = p;
    i++;
  }
}

void Print(LinkList link) {
  LinkList p = link->next;
  std::cout << "Output link: " << std::endl;
  while (p) {
    std::cout << p->data << " ";
    p = p->next;
  }
}

void Clear(LinkList &link) {
  if (link) {
    LinkList p;
    p = link->next;
    while (p) {
      link->next = p->next;
      free(p);
      p = NULL;
      p = link->next;
    }
    free(link);
    link = NULL;
  }
}

int main(void) {
  LinkList la, lb, lc;
  CreatLink(la);
  CreatLink(lb);
  CreatLink(lc);

  Merge(la, lb, lc);

  Print(la);

  Clear(la);
  Clear(lb);
  Clear(lc);
}