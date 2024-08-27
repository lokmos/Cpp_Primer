#ifndef MULTISET_H
#define MULTISET_H

#include "RBTree.h"

template <typename Key> class MultiSet {
private:
    RedBlackTree<Key, size_t> rbTree;
    size_t sz;
public:
    MultiSet() : sz(0) {}
    ~MultiSet() {}

    void insert(const Key &key) {
        auto count = rbTree.at(key);
        if (count != nullptr) 
            ++(*count);
        else
            rbTree.insert(key, 1);
        ++sz;
    }

    void erase(const Key &key) {
        auto count = rbTree.at(key);
        if (!count)
            return;

        --(*count);
        --sz;
        if (*count == 0)
            rbTree.remove(key);
    }

    size_t size() const {return sz;}
    bool empty() const {return sz == 0;}

    size_t count(const Key &key) {
        auto num = rbTree.at(key);
        return num ? *num : 0;
    }

    void clear() {
        rbTree.clear();
        sz = 0;
    }
};

#endif