#include "static_linklist.h"
template <typename T>
SLinkListProcess<T>::SLinkListProcess() {
  // 初始化静态链表 void initSpaceSL();
  // slink_list_[0].cur = 1, 是头节点
  for (int i = 0; i < MAXSIZE; ++i) {
    slink_list_[i].setCurIndex(i + 1);
  }
  slink_list_[MAXSIZE - 1].setCurIndex(0);
};

template <typename T>
SLinkListProcess<T>::~SLinkListProcess(){};

template <typename T>
T SLinkListProcess<T>::mallocSL() {
  // 当前节点
  int cur_indx = slink_list_[0].getCurIndex();

  // 移动头节点指针指向下一个节点
  if (cur_indx != 0) {
    slink_list_[0].setCurIndex(slink_list_[cur_indx].getCurIndex());
  }
  return cur_indx;
}

template <typename T>
void SLinkListProcess<T>::freeSL(int k) {
  if (k < 0 || k > MAXSIZE) {
    return;
  }
  slink_list_[k].setCurIndex(slink_list_[0].getCurIndex());
  slink_list_[0].setCurIndex(k);
}

template <typename T>
void SLinkListProcess<T>::traverse() {
  int i = 1;
  while (slink_list_[i].getCurIndex() != 0) {
    std::cout << slink_list_[i].getData() << ", ";
    i = slink_list_[i].getCurIndex();  // 指针向下移动
  }
  // 尾结点输出
  std::cout << slink_list_[i].getData() << std::endl;
}

template <typename T>
void SLinkListProcess<T>::saveData(const T data) {
  int cur_indx = slink_list_[0].getCurIndex();
  slink_list_[cur_indx].setData(data);
}

template <typename T>
void SLinkListProcess<T>::getData(int len) {
  if (len < 0 || len > MAXSIZE) {
    return;
  }

  T input;
  for (int i = 0; i < len; i++) {
    std::cout << "Please input data: ";
    std::cin >> input;
    mallocSL();
    saveData(input);
  }
  slink_list_[slink_list_[0].getCurIndex()].setCurIndex(0);
  slink_list_[0].setCurIndex(len + 2);
}

template <typename T>
void SLinkListProcess<T>::difference(SLinkListProcess<T>& lb) {
  int indx_tail, indx_la, indx_lb;  // 尾指针, A/B指针
  int indx_la_pre = 1;

  indx_lb = 2;
  indx_la_pre = 1;
  while (lb.slink_list_[0].getCurIndex() != indx_lb) {
    indx_la = slink_list_[1].getCurIndex();
    indx_la_pre = 1;

    while (slink_list_[indx_la].getCurIndex() != 0 && lb.slink_list_[indx_lb].getData() != slink_list_[indx_la].getData()) {
      indx_la_pre = indx_la;
      indx_la = slink_list_[indx_la].getCurIndex();
    }

    // B中的元素不在A中则插入
    if (slink_list_[indx_la].getCurIndex() == 0 && lb.slink_list_[indx_lb].getData() != slink_list_[indx_la].getData()) {
      indx_tail = mallocSL();
      slink_list_[indx_la].setCurIndex(indx_tail);
      slink_list_[indx_tail].setData(lb.slink_list_[indx_lb].getData());
      slink_list_[indx_tail].setCurIndex(0);
    } else {
      // B中的元素在A中则删除A中的元素
      // 修改上一个元素，使其指针越过删除元素
      slink_list_[indx_la_pre].setCurIndex(slink_list_[indx_la].getCurIndex());
      freeSL(indx_la);
    }

    ++indx_lb;
  }
}