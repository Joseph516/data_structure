#include "stack.h"

void initialStack(Stack *s, int max_size) {
  if (max_size != 0) {
    max_size = MAX_STACKSIZE;
  }

  (*s).base = (ElemType *)malloc(sizeof(ElemType) * max_size);
  // Allocation failed.
  if (!(*s).base) {
    printf("Allcoation failed in stack initialization!\n");
    exit(EXIT_FAILURE);
  }

  (*s).top = 0;
  (*s).stack_size = max_size;
}

void destroyStack(Stack *s) {
  if ((*s).base) {
    free((*s).base);
    (*s).base = NULL;
  }

  (*s).top = 0;
  (*s).stack_size = 0;
}

void clearStack(Stack *s) {
  (*s).top = 0;
}

bool stackEmpty(Stack *s) {
  return ((*s).top != 0);
}

int stackLength(Stack *s) {
  return (*s).top;
}

ElemType getTop(Stack *s) {
  return *((*s).base + (*s).top);
}

void push(Stack *s, ElemType e) {
  if ((*s).top >= (*s).stack_size) {
    exit(EXIT_FAILURE);
  }
  *((*s).base + (*s).top) = e;
  ++((*s).top);
}


