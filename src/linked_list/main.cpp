#include <iostream>

using namespace std;

template <class T> class Node {
private:
  T value;

public:
  Node *next;

  T getValue() {
    return value;
  }

  Node(T value) : value(value) {
    next = nullptr;
  }

  Node(T value, Node *p) : value(value), next(p) {}
};

template <class T> class LinkedList {
private:
  Node<T> *head;
  int size = 0;

public:
  void Add(T value) {
    Node<T> *node = new Node<T>(value);

    if (node) {
      node->next = head;
      head = node;
      size++;
    }
  }

  void Print() {
    if (head != nullptr) {
      Node<T> *n = head;

      while (n) {
        cout << n->getValue() << endl;
        n = n->next;
      }
    }
  }

  int getSize() {
    return size;
  }
};

int main(int argc, char *argv[]) {
  LinkedList<int> *list = new LinkedList<int>;
  list->Add(15);
  list->Add(21);
  list->Add(30);

  cout << "List size: " << list->getSize() << endl << endl;

  list->Print();

  return 0;
}