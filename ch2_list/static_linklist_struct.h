#ifndef _SLS_H_
#define _SLS_H_

template <typename T>
class SLinkList {
  public:
  SLinkList();
  ~SLinkList();

  void setData(const T data);

  void setCurIndex(const int cur);

  int getCurIndex();

  T getData();

  private:
  T data_;
  int cur_;
};

#endif
