#ifndef MAP_H
#define MAP_H

#include "RBTree.h"

template <typename Key, typename Value> class Map {
private:
    RedBlackTree<Key, Value> rbTree;
public:
    Map() : rbTree() {}
    ~Map() = default;

    void insert(const Key &key, const Value &value) {rbTree.insert(key, value);}
    void erase(const Key &key) {rbTree.remove(key);}
    size_t size() const {return rbTree.getSize();}
    bool empty() const {return rbTree.empty();}
    bool contains(const Key &key) {return rbTree.at(key) != nullptr;}

    Value &at(const Key &key) {
        auto value = rbTree.at(key);
        if (value == nullptr)
            throw std::out_of_range("Key not found");
        return *value;
    }

    Value &operator[](const Key &key) {
        auto value = rbTree.at(key);
        if (value)
            return *value;
        else {
            rbTree.insert(key, Value());
            return *rbTree.at(key);
        }
    }
};

#endif