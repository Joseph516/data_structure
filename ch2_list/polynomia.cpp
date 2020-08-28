#include "polynomia.h"

// 构建多项式
void Polynomia::insertPoly(float coef, int expn) {
  Poly *p = new Poly;
  p->coef_ = coef;
  p->expn_ = expn;

  // 先进先出方式
  // p->next_ = head_->next_;
  // head_->next_ = p;

  // 先进后出方式
  tail_->next_ = p;
  tail_ = p;
  tail_->next_ = NULL;

  p = NULL;
  ++length_;
}

// 清除多项式
void Polynomia::destroyPoly() {
  Poly *p_curr = head_;
  while (p_curr->next_) {
    Poly *p = p_curr->next_;
    p_curr->next_ = p->next_;
    delete p;
    p = NULL;
  }
  length_ = 0;
}

// 显示多项式
void Polynomia::displayPoly() {
  Poly *p_curr = head_;
  while (p_curr->next_) {
    Poly *p = p_curr->next_;
    std::cout << p->coef_ << "x^" << p->expn_;
    p_curr = p;

    if (p_curr->next_) {
      std::cout << "+";
    }
  }
  std::cout << std::endl;
}
