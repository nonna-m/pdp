#include <iostream>

class Node {
  public:
    Node *right;
    Node *left;
    int data;
    Node(int value) {
      data = value;
      left = NULL;
      right = NULL;
    }
    ~Node() {}
};

class BinaryTree {
  Node *_root;
  public:
    BinaryTree(int root) {
      _root = new Node(root);
    }
    ~BinaryTree() {}
    int insert(int value);
    bool search(int value);
    Node* getRoot();
};

Node* BinaryTree::getRoot() {
  return _root;
}

int BinaryTree::insert(int value) {
  Node* next = getRoot();
  while (next != NULL) {
    if (value > next->data) {
      if (next->right == NULL) {
        next->right = new Node(value);
        return next->right->data;
      } else {
        next = next->right;
      }
    } else {
      if (next->left == NULL) {
        next->left = new Node(value);
        return next->left->data;
      } else {
        next = next->left;
      }
    }
  }
}

bool BinaryTree::search(int value) {
  Node* element = getRoot();
  while (element != NULL) {
    if (value > element->data) {
      element = element->right;
    } else if (value < element->data){
      element = element->left;
    } else {
      return true;
    }
  }
  return false;
}

int main() {
  BinaryTree bt(10);
  std::cout << "Inserting - " << bt.insert(15) << std::endl;
  std::cout << "Inserting - " << bt.insert(5) << std::endl;
  std::cout << "Inserting - " << bt.insert(3) << std::endl;
  std::cout << "Inserting - " << bt.insert(18) << std::endl;
  std::cout << "Inserting - " << bt.insert(18) << std::endl;
  std::cout << "Inserting - " << bt.insert(108) << std::endl;
  std::cout << "Inserting - " << bt.insert(8) << std::endl;
  std::cout << "Searching... - " << bt.search(10) << std::endl;
  std::cout << "Searching... - " << bt.search(108) << std::endl;
  std::cout << "Searching... - " << bt.search(18) << std::endl;
  std::cout << "Searching... - " << bt.search(3) << std::endl;
  std::cout << "Searching... - " << bt.search(5) << std::endl;
  std::cout << "Searching... - " << bt.search(15) << std::endl;
  std::cout << "Searching... - " << bt.search(105) << std::endl;
  return 0;
}

