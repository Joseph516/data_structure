#include <cstdlib>

void convert(int *a[], int n) {
  a = (int **)malloc(sizeof(int *) * n);
  for (int i = 0; i < n; i++) {
    a[i] = (int *)malloc(sizeof(int) * n);
  }

  for (int i = 0; i < n; i++) {
    free(a[i]);
    // a[i] = NULL;
  }
  free(a);
}

int main(void) {
  return 0;
}