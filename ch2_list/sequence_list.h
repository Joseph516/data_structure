#ifndef _SEQUENCE_LIST_H_
#define _SEQUENCE_LIST_H_

#include <cstdlib>
#include <iostream>

const int LIST_INIT_SIZE = 100;  // 默认list容量
const int LISTCREMENT = 10;      // list每次扩容增量

template <typename T>
class SqList {
  public:
  // 算法2.3
  SqList(T v = 0) {
    elem_ = new T[LIST_INIT_SIZE];
    // 初始化数据
    for (int i = 0; i < LIST_INIT_SIZE; i++) {
      elem_[i++] = v;
    }
    length_ = 0;
    list_size_ = LIST_INIT_SIZE;
  }

  // 算法2.2：求C=A+B，A,B,C均为非递减序列
  SqList(SqList<T> const &la, SqList<T> const &lb) {
    elem_ = new T[LIST_INIT_SIZE];
    // 初始化数据
    for (int i = 0; i < LIST_INIT_SIZE; i++) {
      elem_[i++] = 0;
    }
    length_ = 0;
    list_size_ = LIST_INIT_SIZE;

    int len_la = la.listLength();
    int len_lb = lb.listLength();

    int ia = 0, ib = 0, i = 0;
    while ((ia < len_la) && (ib < len_lb)) {
      if (la.getElem(ia) < lb.getElem(ib)) {
        (this)->listInsert(i++, la.getElem(ia));
        ++ia;
      } else {
        (this)->listInsert(i++, lb.getElem(ib));
        ++ib;
      }
    }

    while (ia < len_la) {
      (this)->listInsert(i++, la.getElem(ia));
      ++ia;
    }

    while (ib < len_lb) {
      (this)->listInsert(i++, lb.getElem(ib));
      ++ib;
    }
  }

  ~SqList() {
    if (elem_) {
      delete[] elem_;
      elem_ = NULL;
    }
  }

  // SqList<T> operator+(const SqList<T> &lb);

  // 将L置为空表
  void clearList();

  // 判断L是否为空表，若为空表则返回TRUE
  bool listEmpty() const {
    return (length_ == 0);
  };

  // 返回L中的数据个数
  int listLength() const {
    return length_;
  };

  // 返回线性表中第i个数据的值
  T getElem(const int i) const;

  // 返回与数据e满足compare关系的数据元素的位序
  int locateElem(T e, bool (*compare)(T lhs, T rhs)) const;

  // 返回e的前驱数据
  T priorElem(T e) const;

  // 返回e的后驱数据
  T nextElem(T e) const;

  // 算法2.4
  // 在第i（0-length_）个位置插入数据，L长度加1
  void listInsert(const int i, const T e);

  // 算法2.5
  // 删除第i个位置数据并返回，L长度减1
  T listDelete(const int i);

  // 遍历输出L
  void listTraverse() const;

  // 算法2.1：A=A∪B
  // 合并线性表，将lb中不存在la中的元素合并进来。
  // 可以重载+=运算符
  void unionList(SqList<T> const &lb);

  // 扩容，动态申请内存
  void expand();

  private:
  T *elem_;        // 储存空间基址
  int length_;     // 当前长度
  int list_size_;  // 当前list容量
};

#endif