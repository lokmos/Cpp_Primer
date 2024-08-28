#ifndef UNORDERED_MAP_H
#define UNORDERED_MAP_H

#include "hash.h"
template <typename Key, typename Value> class Unordered_map {
private:
    HashTable<Key, Value> hashtable;

public:
    Unordered_map() : hashtable() {}
    ~Unordered_map() = default;

    bool empty() const { return hashtable.size() == 0;}
    size_t size() const { return hashtable.size();}
    void clear() { hashtable.clear();}
    void insert(const Key &key, const Value &value) { hashtable.insert(key, value);}
    void erase(const Key &key) { hashtable.erase(key);}
    bool find(const Key &key) { return hashtable.find(key) != nullptr; }

    Value &operator[](const Key &key) {
        Value *ans = hashtable.find(key);
        if (ans != nullptr) {
        return *ans;
        }
        hashtable.insertKey(key);
        ans = hashtable.find(key);
        return *ans;
    }
};

#endif