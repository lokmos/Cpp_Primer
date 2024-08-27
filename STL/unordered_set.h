#ifndef UNORDERED_SET_H
#define UNORDERED_SET_H

#include "hash.h"

template <typename Key> class Unordered_set {
public:
    Unordered_set() : hashTable() {}

    ~Unordered_set() = default;

    bool empty() const {return hashTable.size() == 0;}
    size_t size() const {return hashTable.size();}
    void clear() {hashtable.clear();}
    void insert(Key key) {hashTable.insert(key, key);}
    void erase(Key key) {hashTable.erase(key);}
    bool find(Key key) {return hashTable.find(key);}
private:
    HashTable<Key, Key> hashTable;
};

#endif