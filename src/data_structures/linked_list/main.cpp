#include <iostream>
#include <list>

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
  Node<T> *head;
  Node<T> *tail;
  int size = 0;

public:
  void PushBack(T value) {
    Node<T> *node = new Node<T>(value);

    if (node != nullptr) {
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
    if (head != nullptr) {
      Node<T> *n = head;

      while (n != nullptr) {
        cout << n->getValue() << endl;
        n = n->next;
      }
    }
  }

  T Pop() {
    if (head != nullptr) {
      T temp = head->getValue();
      Node<T> *n = head->next;
      delete head;
      size--;

      if (n != nullptr) {
        head = n;
        head->prev = nullptr;
      } else {
        head = nullptr;
      }

      return temp;
    }
  }

  ~LinkedList() {
    while (head != nullptr) {
      Pop();
    }
  }

  int getSize() {
    return size;
  }
};

int main(int argc, char *argv[]) {
  LinkedList<int> *list = new LinkedList<int>;

  // list->PushBack(15);
  // list->PushBack(21);
  // list->PushBack(30);

  // list->Pop();

  // cout << list->getHead()->getValue() << endl;

  // std::list<int> vec;
  // vec.push_back(15);
  // vec.push_back(21);
  // vec.push_back(30);

  // vec.pop_back();

  // cout << vec.front() << endl;

  // cout <<  << endl;


  // cout << "List size: " << list->getSize() << endl << endl;

  // list->Print();

  // cout << list->getHead()->next->getValue() << endl;

  // list->~LinkedList();

  // cout << endl << "List size: " << list->getSize() << endl << endl;

  return 0;
}