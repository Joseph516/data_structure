#include "../polynomia.cpp"

int main(void) {
  // 多项式默认为有序
  Polynomia pa;
  pa.insertPoly(1, 0);
  pa.insertPoly(3, 5);
  pa.insertPoly(5, 10);
  pa.displayPoly();

  Polynomia pb;
  pb.insertPoly(8, 1);
  pb.insertPoly(22, 5);
  pb.insertPoly(-5, 8);
  pb.displayPoly();

  Polynomia pc = pa + pb;
  // Polynomia pc = pa;
  pc.displayPoly();

  return 0;
}