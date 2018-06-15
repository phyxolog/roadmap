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

  Node(const T &value, Node *next = nullptr)
    : value(value), next(next) {}
};

template <typename T>
class Stack {
private:
  Node<T> *head = nullptr;
  unsigned int size = 0;

public:
  void push(T value) {
    Node<T> *n = new Node<T>(value, head);
    head = n;
    size++;
  }

  T pop() {
    if (head != nullptr) {
      T temp = head->getValue();
      Node<T> *n = head->next;

      delete head;
      head = n;

      size--;
      return temp;
    }

    return T();
  }

  T peek() {
    if (head != nullptr) {
      return head->getValue();
    }

    return T();
  }

  unsigned int getSize() {
    return size;
  }
};

int main(int argc, char *argv[]) {
  Stack<int> *stack = new Stack<int>;

  stack->push(5);
  stack->push(6);

  cout << "Size: " << stack->getSize() << endl; // 2
  cout << stack->peek() << endl;                // 6
  cout << stack->pop() << endl;                 // 6
  cout << stack->pop() << endl;                 // 5
  cout << stack->pop() << endl;                 // -1 because now stack was empty

  return 0;
}