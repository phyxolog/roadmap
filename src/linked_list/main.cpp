#include <iostream>

using namespace std;

template <class T> class Node {
private:
  T *value;

public:
  Node *next;

  T getValue() {
    return *value;
  }

  Node(T value) : value(&value) {
    next = nullptr;
  }

  Node(T value, Node *p) : value(value), next(p) {}
};

int main(int argc, char *argv[]) {
  Node<int> *n = new Node<int>(15);
  cout << n->getValue() << endl;
  return 0;
}