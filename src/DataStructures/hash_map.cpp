//
// Created by phyxolog on 03.08.18.
//

#include <iostream>

using namespace std;

template<typename K, typename V>
class Entry {
private:
    K key;
    V value;

public:
    Entry * next;
    Entry(const K &key, const V &value, Entry *next = nullptr)
            : key(key), value(value), next(next) {}

    K getKey() {
        return key;
    }

    V getValue() {
        return value;
    }

    void setKey(K key) {
        Entry::key = key;
    }

    void setValue(V value) {
        Entry::value = value;
    }
};

// HashMap with fixed size (128)
// And may have only integer type of key
template<typename K, typename V>
class HashMap {
private:
    Entry<K, V> **table;
    int size = 0;
    int tableSize = 128;

    unsigned long hashFunc(K key) {
        return key % tableSize;
    }

public:
    HashMap() {
        table = new Entry<K, V> *[tableSize]();
    }

    V get(const K &key) {
        unsigned long hash = hashFunc(key);
        Entry<K, V> *entry = table[hash];

        while (entry != nullptr) {
            if (entry->getKey() == key) {
                return entry->getValue();
            }

            entry = entry->next;
        }

        return V();
    }

    void put(const K &key, const V &value) {
        unsigned long hash = hashFunc(key);
        Entry<K, V> *prev = nullptr;
        Entry<K, V> *entry = table[hash];

        while (entry != nullptr && entry->getKey() != key) {
            prev = entry;
            entry = entry->next;
        }

        if (entry == nullptr) {
            entry = new Entry<K, V>(key, value);

            if (prev == nullptr) {
                table[hash] = entry;
            }
            else {
                prev->next = entry;
            }

            size++;
        }
        else {
            entry->setValue(value);
        }
    }

    void del(const K &key) {
        unsigned long hash = hashFunc(key);
        Entry<K, V> *prev = nullptr;
        Entry<K, V> *entry = table[hash];

        while (entry != nullptr && entry->getKey() != key) {
            prev = entry;
            entry = entry->next;
        }

        if (entry != nullptr) {
            if (prev == nullptr) {
                table[hash] = entry->next;
            }
            else {
                prev->next = entry->next;
            }

            size--;
            delete entry;
        }
    }
};

int main(int argc, char *argv[]) {
    HashMap<int, string> *map = new HashMap<int, string>;
    map->put(1, "1");
    map->put(2, "12");
    map->put(3, "13");
    map->del(1);

    cout << map->get(1) << endl; // null
    cout << map->get(2) << endl; // 12
    cout << map->get(3) << endl; // 13

    return 0;
}