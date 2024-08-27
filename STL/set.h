#ifndef SET_H
#define SET_H

#include "RBTree.h"

template <typename Key> class Set {
public:
    Set() : rbTree() {}
    void insert(const Key &key) {rbTree.insert(key, key);}
    void erase(const Key &key) {rbTree.erase(key);}
    size_t size () const {return rbTree.getSize();}
    bool empty() const {return rbTree.empty();}
    bool contains(const Key &key) {return rbTree.contains(key);}
private:
    RedBlackTree<Key, Key> rbTree;
};

#endif