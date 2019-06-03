#ifndef _STATIC_LINKLIST_H_
#define _STATIC_LINKLIST_H_

#include <iostream>
#include "../status.h"
#include "static_linklist_struct.h"

const int MAXSIZE = 1000;

template <typename T>
class SLinkListProcess : public SLinkList<T> {
  public:
  SLinkListProcess();

  ~SLinkListProcess();

  // 申请空间：头加点cur依次向下取值（1,2,3...），相当于指向下个节点。
  T mallocSL();

  // 释放指针结点k：使头结点指向k，k结点指向头结点
  void freeSL(int k);

  // 获取输入数据
  void getData(int len);

  // 保存数据
  void saveData(const T data);

  // 遍历输出
  void traverse();

  // TODO：该算法逻辑还是不是很清楚
  // 算法2.16：求(A-B)U(B-A)：找到AUB集合中仅出现一次的元素
  // 默认：A，B集合中元素最开始都不重复
  void difference(SLinkListProcess& lb);

  private:
  SLinkList<T> slink_list_[MAXSIZE];
};

#endif