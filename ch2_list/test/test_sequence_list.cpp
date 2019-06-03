#include "../sequence_list.cpp"

int main(void) {
  SqList<int> L(0);

  L.listInsert(0, 1);
  L.listInsert(1, 2);
  L.listInsert(2, 3);
  L.listInsert(1, 4);
  L.listTraverse();

  int e = L.getElem(2);
  std::cout << e << std::endl;

  int indx = L.locateElem(2, equal);
  std::cout << "Location:" << indx << std::endl;

  int prior = L.priorElem(2);
  std::cout << "prior:" << prior << std::endl;

  int next = L.nextElem(2);
  std::cout << "next:" << next << std::endl;

  int e_delete = L.listDelete(1);
  L.listTraverse();

  bool is_empty = L.listEmpty();
  std::cout << "Emptys:" << is_empty << std::endl;

  std::cout << L.listLength() << std::endl;

  L.clearList();

  return 0;
}