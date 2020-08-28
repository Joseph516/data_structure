#include "../static_linklist.cpp"
#include "../static_linklist_struct.cpp"

int main(void) {
  // 建立链表A
  std::cout << "Building list A." << std::endl;
  SLinkListProcess<char> sllist_a;
  sllist_a.getData(4);
  sllist_a.traverse();

  // 建立链表B
  std::cout << "Building list B." << std::endl;
  SLinkListProcess<char> sllist_b;
  sllist_b.getData(4);

  // 求(A-B)U(B-A)：找到AUB集合中仅出现一次的元素
  sllist_a.difference(sllist_b);


  sllist_a.traverse();


  return 0;
}