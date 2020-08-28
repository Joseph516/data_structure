#include "sequence_list.h"
#include "../status.h"

template <typename T>
void SqList<T>::clearList() {
  for (int i = 0; i < length_; i++) {
    elem_[i] = 0;
  }
  length_ = 0;
  list_size_ = LIST_INIT_SIZE;
}

template <typename T>
T SqList<T>::getElem(const int i) const {
  if (length_ == 0) {
    std::cerr << "There is no element in list!" << std::endl;
    return ERROR;
  } else if ((i >= 0) && (i < length_)) {
    return elem_[i];
  } else {
    std::cerr << "Please input the right index!" << std::endl;
    return ERROR;
  }
}

template <typename T>
int SqList<T>::locateElem(T e, bool (*compare)(T lhs, T rhs)) const {
  for (int i = 0; i < length_; ++i) {
    if ((*compare)(elem_[i], e)) {
      return i;
    }
  }
  // 未找到目前元素
  std::cerr << "Can't find the element!" << std::endl;
  return -1;
}

template <typename T>
T SqList<T>::priorElem(T e) const {
  int i = 0;
  while (i < length_ && elem_[i] != e) {
    ++i;
  }

  if (i > 0) {
    return elem_[i - 1];
  } else {
    std::cerr << "No prior data founded.";  // 第一个元素无前继
    return ERROR;
  }
}

template <typename T>
T SqList<T>::nextElem(T e) const {
  int i = 0;
  while (i < length_ && elem_[i] != e) {
    ++i;
  }

  if (i < length_ - 1) {
    return elem_[i + 1];
  } else {
    std::cerr << "No next data founded.";  // 最后一个元素无后继
    return ERROR;
  }
}

template <typename T>
void SqList<T>::listInsert(const int i, const T e) {
  // 扩容操作
  expand();
  if ((i >= 0) && (i <= length_)) {
    if (length_ == list_size_) {
      std::cerr << "The lists is full." << std::endl;  // 可以去除
    } else {
      for (int j = length_; j > i; --j) {
        elem_[j] = elem_[j - 1];
      }
      elem_[i] = e;
      ++length_;
    }
  } else {
    std::cerr << "Wrong insert position!" << std::endl;
  }
}

template <typename T>
T SqList<T>::listDelete(const int i) {
  if (listEmpty()) {
    std::cerr << "The lists is empty." << std::endl;
  } else if (length_ == 1) {
    clearList();
  } else if ((i >= 0) && (i < length_)) {
    T elem_delete = elem_[i];
    for (int j = i; j < length_ - 1; ++j) {
      elem_[j] = elem_[j + 1];
    }
    --length_;
    return elem_delete;
  } else {
    std::cerr << "Wrong delete position!" << std::endl;
  }
}

template <typename T>
void SqList<T>::listTraverse() const {
  for (int i = 0; i < length_; ++i) {
    std::cout << elem_[i] << ", ";
  }
  std::cout << std::endl;
}

template <typename T>
void SqList<T>::unionList(SqList<T> const &lb) {
  int len_la = listLength();
  int len_lb = lb.listLength();

  for (int i = 0; i < len_lb; ++i) {
    T temp_lb = lb.getElem(i);
    if (locateElem(temp_lb, equal) == -1) {
      listInsert(len_la++, temp_lb);
    }
  }
}

template <typename T>
void SqList<T>::expand() {
  if (length_ < list_size_) {
    return;
  } else {
    T *elem_old = elem_;
    list_size_ += LISTCREMENT;
    elem_ = new T[list_size_];

    for (int i = 0; i < length_; ++i) {
      elem_[i] = elem_old[i];
    }

    delete[] elem_old;
    elem_old = NULL;
  }
}
