// 存储结构
#include <cstdlib>

typedef enum { ATOM, LISTS } ElemTag;
typedef int AtomType;

typedef struct GLNode {
  ElemTag tag;

  union {
    AtomType atom;
    struct {
      struct GlNode *hp, *tp;
    } ptr;
  };
} GLNode, *GLists;

int main() {
  GLists p;
  p->tag = LISTS;
  //   p->atom = 1;
  p->ptr.hp = NULL;  // if *ptr is defined in union, then use p->ptr->hp;
  p->ptr.tp = NULL;
}
