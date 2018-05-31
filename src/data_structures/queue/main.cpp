#include <iostream>

using namespace std;

template <typename T>
class Node {
private:
  T value;

public:
  Node<T> *next;

  T getValue() {
    return value;
  }

  Node(T value, Node *next = nullptr) : value(value), next(next) {}
};

template <typename T>
class Queue {
private:
  Node<T> *first;
  Node<T> *last;
  unsigned int size = 0;

public:
  void enqueue(T value) {
    Node<T> *n = new Node<T>(value);

    if (first != nullptr) {
      last->next = n;
      last = last->next;
    } else {
      first = last = n;
    }

    size++;
  }

  T dequeue() {
    if (first != nullptr) {
      T temp = first->getValue();

      Node<T> *n = first->next;
      delete first;
      first = n;

      return temp;
    }

    return -1;
  }

  ~Queue() {
    while (first != nullptr) {
      dequeue();
    }
  }

  unsigned int getSize() {
    return size;
  }
};

int main(int argc, char *argv[]) {
  Queue<int> *queue = new Queue<int>;

  queue->enqueue(5);
  queue->enqueue(6);
  queue->enqueue(10);
  queue->enqueue(8);

  cout << "Size: " << queue->getSize() << endl;     // 2

  cout << queue->dequeue() << endl;                 // 5
  cout << queue->dequeue() << endl;                 // 6
  cout << queue->dequeue() << endl;                 // 10
  cout << queue->dequeue() << endl;                 // 8
  cout << queue->dequeue() << endl;                 // -1 because now queue was empty

  return 0;
}