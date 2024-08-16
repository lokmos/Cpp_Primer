#ifndef MYVECTOR_H
#define MYVECTOR_H

template <typename T>
class Vector {
private:
    T* elements;
    size_t size;
    size_t capacity;
public:
    // 构造函数
    Vector() : elements(nullptr), size(0), capacity(0) {};

    
};

#endif