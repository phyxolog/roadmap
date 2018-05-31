#include <iostream>

using namespace std;

template <class T> class Node {
private:
  T value;

public:
  Node *next;
  Node *prev;

  T getValue() {
    return value;
  }

  Node(T value, Node *next = nullptr, Node *prev = nullptr)
    : value(value), next(next), prev(prev) {}
};

template <class T> class LinkedList {
private:
  Node<T> *head; // pointer to first node
  Node<T> *tail; // pointer to last node
  int size = 0;

public:
  void PushBack(T value) {
    // first off create new node.
    Node<T> *node = new Node<T>(value);

    // if memory allocated
    if (node != nullptr) {      
      // then check if head != null
      if (head != nullptr) {
        tail->next = node;
        node->prev = tail;
        tail = node;
      } else {        
        head = tail = node;
      }

      size++;
    }
  }

  void PushFront(T value) {
    Node<T> *node = new Node<T>(value);

    if (node != nullptr) {
      if (head != nullptr) {
        head->prev = node;
        node->next = head;
        head = node;
      } else {        
        head = tail = node;
      }

      size++;
    }
  }

  Node<T> *getHead() {
    return head;
  }

  Node<T> *getTail() {
    return tail;
  }

  void Print() {
    // start printing from head
    if (head != nullptr) {
      Node<T> *n = head;

      while (n != nullptr) {
        cout << n->getValue() << endl;
        n = n->next;
      }
    }
  }

  T PopFront() {
    if (head != nullptr) {
      // remember a value
      T temp = head->getValue();

      // get next node and delete current
      Node<T> *n = head->next;
      delete head;

      // decrement list size
      size--;

      if (n != nullptr) {
        head = n;
        head->prev = nullptr;
      } else {
        head = tail = nullptr;
      }

      return temp;
    }
  }

  T PopBack() {
    // similar to PopFront, but work from the end
    if (tail != nullptr) {
      T temp = tail->getValue();
      Node<T> *n = tail->prev;
      delete tail;
      size--;

      if (n != nullptr) {
        tail = n;
        n->next = nullptr;
      } else {
        head = tail = nullptr;
      }
      
      return temp;
    }
  }

  ~LinkedList() {
    while (head != nullptr) {
      PopFront();
    }
  }

  int getSize() {
    return size;
  }
};

int main(int argc, char *argv[]) {
  LinkedList<int> *list = new LinkedList<int>;

  list->PushFront(15);
  list->PushFront(21);
  list->PushFront(30);

  cout << "Pops: " << endl;
  cout << list->PopBack() << endl; // 30
  cout << list->PopBack() << endl; // 15
  cout << list->PopBack() << endl; // 21
  cout << list->PopBack() << endl << endl; // 0 because now list was empty

  list->PushBack(43);
  list->PushBack(42);
  list->PushBack(41);

  cout << "Tail: " << list->getTail()->getValue() << endl << endl; // 41

  cout << "List size: " << list->getSize() << endl << endl; // 3

  list->Print();

  list->~LinkedList();

  cout << endl << "List size: " << list->getSize() << endl << endl;

  return 0;
}