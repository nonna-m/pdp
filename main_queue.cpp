#include <iostream>

class Queue {
  unsigned _head;
  unsigned  _tail;
  unsigned  _size;
  int *_arr;
  public:
  Queue(int size = 10) {
    _head = 0;
    _tail = 0;
    _size = size;
    _arr = new int [_size];
  }
  ~Queue() {
    delete [] _arr;
  }
  int dequeue();
  void enqueue(int element);
  int peek();
  unsigned int size();
  bool isEmpty();
  bool isFull();
  void printQueue();
};

int Queue::dequeue() {
  if (isEmpty()) {
    std::cout << "Error: Queue is empty." << std::endl;
    return 1;
  }
  _head += 1;
  if (_head == _size) {
    _head = 0;
    return _arr[_size - 1];
  }
  return _arr[_head - 1];
}

void Queue::enqueue(int element) {
  if (isFull()) {
    std::cout << "Error: Queue is full." << std::endl;
  } else {
    _tail += 1;
    if (_tail == _size) {
      _tail = 0;
      _arr[_size - 1] = element;
    } else {
      _arr[_tail - 1] = element;
    }
  }
}

int Queue::peek() {
  if (isEmpty()) {
    std::cout << "Error: Queue is empty." << std::endl;
    return 1;
  }
  return _arr[_head];
}

unsigned Queue::size() {
  return _tail - _head;
}

bool Queue::isEmpty() {
  return _tail == _head;
}

bool Queue::isFull() {
  return size() == _size;
}

void Queue::printQueue() {
  int el = _head;
  std::cout << "Printing the queue: ";
  for (int i = 0; i < size(); i++) std::cout << _arr[el++] << " ";
  std::cout << std::endl;
}

int main() {
  Queue queue(10);
  std::cout << "Is queue empty? " << queue.isEmpty() << std::endl;
  std::cout << "First element in the queue: " << queue.peek() << std::endl;
  std::cout << "Dequeue: " << queue.dequeue() << std::endl;
  std::cout << "The size of the queue: " << queue.size() << std::endl;
  queue.enqueue(10);
  std::cout << "Enqueue 10." << std::endl;
  queue.enqueue(45);
  std::cout << "Enqueue 45." << std::endl;
  queue.enqueue(7);
  std::cout << "Enqueue 7." << std::endl;
  std::cout << "First element in the queue: " << queue.peek() << std::endl;
  queue.printQueue();;
  std::cout << "Dequeue: " << queue.dequeue() << std::endl;
  queue.enqueue(9);
  std::cout << "Enqueue 9." << std::endl;
  std::cout << "The size of the queue: " << queue.size() << std::endl;
  std::cout << "Is queue full? " << queue.isFull() << std::endl;
  queue.printQueue();
  return 0;
}
