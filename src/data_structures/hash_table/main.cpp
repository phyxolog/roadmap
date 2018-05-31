#include <iostream>

using namespace std;

template<typename K, typename V>
class HashEntry {
private:
  K key;
  V value;

public:
  HashEntry(K key, V value) : key(key), value(value) {}

  K getKey() {
    return key;
  }

  V getValue() {
    return value;
  }
};

int main(int argc, char *argv[]) {
  return 0;
}