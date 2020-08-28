#include "../sequence_list.cpp"

int main(void) {
  SqList<int> list_la(0);

  list_la.listInsert(0, 1);
  list_la.listInsert(1, 4);
  list_la.listInsert(2, 7);

  SqList<int> list_lb(0);

  list_lb.listInsert(0, 2);
  list_lb.listInsert(1, 5);
  list_lb.listInsert(2, 8);

  SqList<int> list_lc(list_la, list_lb);

  list_lc.listTraverse();

  std::cout << list_lc.listLength() << std::endl;

  return 0;
}