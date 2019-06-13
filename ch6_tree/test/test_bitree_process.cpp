#include "../bitree_process.cpp"

int main(void) {
  // 创建二叉树：
  // for example:abc^^de^g^^f^^^
  // for example:-+a^^*b^^-c^^d^^/e^^f^^
  BiTreeProcess bi;
  
  // 二叉树递归遍历测试
  std::cout << "preOrderTraverse result: ";
  bi.preOrderTraverse(bi.getRoof());
  std::cout << std::endl;

  std::cout << "inOrderTraverse result: ";
  bi.inOrderTraverse(bi.getRoof());
  std::cout << std::endl;

  std::cout << "postOrderTraverse result: ";
  bi.postOrderTraverse(bi.getRoof());
  std::cout << std::endl;

  // 非递归遍历二叉树
  std::cout << "preOrderNonRecursion result: ";
  bi.preOrderNonRecursion();  
  std::cout << std::endl;

  std::cout << "inOrderNonRecursion result: ";
  bi.inOrderNonRecursion();  
  std::cout << std::endl;

  std::cout << "postOrderNonRecursion result: ";
  bi.postOrderNonRecursion();  
  std::cout << std::endl;

  return 0;
}