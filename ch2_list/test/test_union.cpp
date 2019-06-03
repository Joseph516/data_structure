#include "../sequence_list.cpp"

int main(void) {
  SqList<int> list_la(0);

  list_la.listInsert(0, 1);
  list_la.listInsert(1, 2);
  list_la.listInsert(2, 3);

  SqList<int> list_lb(0);

  list_lb.listInsert(0, 7);
  list_lb.listInsert(1, 4);
  list_lb.listInsert(2, 5);

  list_la.unionList(list_lb);
  list_la.listTraverse();

  std::cout << list_la.listLength() << std::endl;

  return 0;
}