#include "static_linklist_struct.h"

template <typename T>
SLinkList<T>::SLinkList() {
}

template <typename T>
SLinkList<T>::~SLinkList() {
}

template <typename T>
void SLinkList<T>::setData(const T data) {
  data_ = data;
}

template <typename T>
void SLinkList<T>::setCurIndex(const int cur) {
  cur_ = cur;
};

template <typename T>
int SLinkList<T>::getCurIndex() {
  return cur_;
}

template <typename T>
T SLinkList<T>::getData() {
  return data_;
}