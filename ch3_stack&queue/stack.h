#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef float ElemType;
static const int MAX_STACKSIZE = 10;

typedef struct {
  ElemType *base;
  int top;
  int stack_size;
} Stack;

// stack initialization
void initialStack(Stack *s, int max_size);

// remove stack
void destroyStack(Stack *s);

// get a empty stack
void clearStack(Stack *s);

bool stackEmpty(Stack *s);

int stackLength(Stack *s);

ElemType getTop(Stack *s);

void push(Stack *s, ElemType e);

void pop(Stack *s, ElemType e);

void stackTraverse(Stack *s, void *visit);
