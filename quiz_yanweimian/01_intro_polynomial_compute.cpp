/**
 * 计算一元多项式的值
 * P(n) = sum(a_i*x^i)
 */

#include <iostream>

float polynomia_Compute(float a[], float x, int n) {
  float p = 0;
  for (int i = n - 1; i > 0; --i) {
    p = (p + a[i]) * x;
  }

  return p + a[0];
}

int main(int argc, const char *argv[]) {
  const int n = 5;
  float a[n] = {1, 2, 3, 4, 5}, x;
  if (argc > 0) {
    x = atof(argv[1]); // get input and turn to float
  }
  else {
    x = 1;
  }
  std::cout << polynomia_Compute(a, x, n) << std::endl;
}