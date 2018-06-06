#include <iostream>

using namespace std;

template<typename K, typename V>
class Entry {
private:
  K key;
  V value;

public:
  Entry *next;
  Entry(K key, V value, Entry next = nullptr) : key(key), value(value), next(next) {}

  K getKey() {
    return key;
  }

  V getValue() {
    return value;
  }
};

template<typename K, typename V>
class HashMap {
private:
  Entry<K, V> **table;
  int size = 0;
  int capacity = 16;

public:
  HashMap() {
    table = new Entry<K, V> *[capacity]();
  }

  unsigned long hashFunc(K key) {
    unsigned long hash = (unsigned long)(key);
    hash ^= (hash >> 20) ^ (hash >> 12);
    return hash ^ (hash >> 7) ^ (hash >> 4);
  }

  int indexFor(unsigned long hash, int tableLength) {
    return hash & (tableLength - 1);
  }

  void put(K key, V value) {
    unsigned long hash = hashFunc(key);
    cout << hash << endl;
  }
};

int main(int argc, char *argv[]) {
  HashMap<int, string> *map = new HashMap<int, string>;
  map->put(51, "1");

  return 0;
}