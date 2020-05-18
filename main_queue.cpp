#include <iostream>

class Queue {
        unsigned _head;
        unsigned  _tail;
        unsigned  _size;
        int *_arr;
        public:
            Queue() {
                _head = 0;
                _tail = 0;
                _size = 10;
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
};

int Queue::dequeue() {
    if (isEmpty()) {
            std::cout << "Error: Queue is empty." << std::endl;
            return 1;
    }
    return _arr[_head++];
}

void Queue::enqueue(int element) {
    if (isFull()) {
        std::cout << "Error: Queue is full." << std::endl;
    } else {
        _arr[_tail++] = element;
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

int main() {
    Queue queue;
    std::cout << "queue.isEmpty() " << queue.isEmpty() << std::endl;
    std::cout << "queue.peek() " << queue.peek() << std::endl;
    std::cout << "queue.dequeue() " << queue.dequeue() << std::endl;
    std::cout << "queue.size() " << queue.size() << std::endl;
    queue.enqueue(10);
    std::cout << "enqueue 10 " << std::endl;
    queue.enqueue(45);
    std::cout << "enqueue 45" << std::endl;
    std::cout << "queue.isEmpty()" << queue.isEmpty() << std::endl;
    queue.enqueue(7);
    std::cout << "enqueue 7" << std::endl;
    std::cout << "queue.peek()" << queue.peek() << std::endl;
    std::cout << "queue.dequeue() " << queue.dequeue() << std::endl;
    queue.enqueue(9);
    std::cout << "enqueue 9" << std::endl;
    std::cout << "queue.size() " << queue.size() << std::endl;
    std::cout << "queue.isFull() " << queue.isFull() << std::endl;
    return 0;
}
