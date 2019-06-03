#ifndef _POLYNOMIA_H_
#define _POLYNOMIA_H_

#include <iostream>

const int MAX_LEN = 50;

typedef struct Poly {
  float coef_;         // 系数
  int expn_;           // 指数
  struct Poly *next_;  // 指针域
} Poly;

// 多项式默认为有序
class Polynomia {
  public:
  Polynomia() {
    // 初始化头结点
    head_ = new Poly;
    head_->coef_ = -1;
    head_->expn_ = -1;
    head_->next_ = NULL;

    tail_ = head_;

    length_ = 0;
  };
  ~Polynomia() {
    destroyPoly();

    if (head_) {
      delete head_;
      head_ = NULL;
    }
    tail_ = NULL;
  };

  // 构建多项式
  void insertPoly(float coef, int expn);

  // 移除多项式
  void destroyPoly();

  // 显示多项式
  void displayPoly();

  bool empty() {
    return (length_ == 0);
  }

  // 多项式相加
  Polynomia operator+(Polynomia &pn) {
    Polynomia pc_link;
    Poly *pa = this->head_->next_;  // 首元素结点
    Poly *pb = pn.head_->next_;     //  首元素结点
    Poly *pc = pc_link.head_;

    // 多项式均不为空情况
    while (pa != NULL && pb != NULL) {
      if (pa->expn_ == pb->expn_) {
        pc_link.insertPoly(pa->coef_ + pb->coef_, pa->expn_);
        pa = pa->next_;
        pb = pb->next_;
      } else if (pa->expn_ < pb->expn_) {
        pc_link.insertPoly(pa->coef_, pa->expn_);
        pa = pa->next_;
      } else {
        pc_link.insertPoly(pb->coef_, pb->expn_);
        pb = pb->next_;
      }
    }

    // 某多项式为空情况
    if (pa == NULL) {
      while (pb != NULL) {
        pc_link.insertPoly(pb->coef_, pb->expn_);
        pb = pb->next_;
      }
    } else {
      pc_link.insertPoly(pa->coef_, pa->expn_);
      pa = pa->next_;
    }
    return pc_link;
  };

  Polynomia operator=(Polynomia &pb) {
    this->head_ = pb.head_;
    this->tail_ = pb.tail_;
    this->length_ = pb.length_;
    return (*this);
  };

  private:
  Poly *head_;
  Poly *tail_;
  int length_;
};

#endif