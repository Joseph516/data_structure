// TODO: 算法待完善

#include <iostream>

// Move No.n plate from x to y
void move(char x[], int n, char y[]) {
}

// hanoi tower problem:
// move chars from x to z
void hanoi(int n, char x[], char y[], char z[]) {
  if (n == 1) {
    move(x, 1, z);
  } else {
    hanoi(n - 1, x, z, y);
    move(x, n, z);
    hanoi(n - 1, y, x, z);
  }
}

int main(void) {
  const int n = 4;
  std::string x;
  std::string y;
  std::string z;

  hanoi(n, x, y, z);
  return 0;
}