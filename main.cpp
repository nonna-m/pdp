#include <iostream>

class Stack {
  unsigned int _size;
  unsigned int _top;
  int *_arr;
  public:
    Stack(unsigned int size = 100) {
      _size = size;
      _top = 0;
      _arr = new int [size];
    }
    ~Stack() {
      delete [] _arr;
    }
    int pop();
    void push(int element);
    bool isEmpty();
    bool isFull();
    unsigned int size();
    int peek();
};

int Stack::pop() {
  if (isEmpty()) {
    std::cout << "Error: Stack is empty." << std::endl;
    return 1;
  }
  return _arr[--_top];
}

void Stack::push(int el) {
  if (isFull()) {
    std::cout << "Error: Stack is full." << std::endl;
  } else {
    _arr[_top++] = el;
  }
}

int Stack::peek() {
  if (isEmpty()) {
    std::cout << "Error: Stack is empty" << std::endl;
    return 1;
  }
  return _arr[_top-1];
}

bool Stack::isEmpty() {
  return _top == 0;
}

bool Stack::isFull() {
  return _top == _size;
}

unsigned int Stack::size() {
  return _top;
}

int main() {
  Stack stack(0);
  std::cout << stack.pop() << std::endl;
  stack.push(1);
  stack.push(10);
  stack.push(5);
  stack.push(4);
  stack.push(4);
  std::cout << stack.isFull() << std::endl;
  std::cout << stack.pop() << std::endl;
  std::cout << stack.pop() << std::endl;
  std::cout << stack.pop() << std::endl;
  std::cout << stack.pop() << std::endl;
  std::cout << stack.pop() << std::endl;
  std::cout << stack.pop() << std::endl;
  std::cout << stack.pop() << std::endl;
  std::cout << stack.pop() << std::endl;
  std::cout << stack.pop() << std::endl;
  stack.push(6);
  std::cout << stack.peek() << std::endl;
  return 0;
}

