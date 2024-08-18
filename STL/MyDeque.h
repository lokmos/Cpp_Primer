#ifndef MYDEQUE_H
#define MYDEQUE_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Deque {
private:
    T* elements;
    size_t capacity;
    size_t size;
    size_t frontIndex;
    size_t backIndex;

public:
    Deque() : elements(nullptr), capacity(0), size(0), frontIndex(0), backIndex(0) {}

    ~Deque() {
        clear();
        delete[] elements;
    }

    void push_front(const T& value) {
        // 如果容量不够，重新分配内存
        if (size == capacity) {
            resize();
        }

        // 更新frontIndex
        frontIndex = (frontIndex - 1 + capacity) % capacity;

        // 在frontIndex处插入元素
        elements[frontIndex] = value;

        // 更新size
        ++size;
    }

    void push_back(const T& value) {
        // 如果容量不够，重新分配内存
        if (size == capacity) {
            resize();
        }

        // 在backIndex处插入元素
        elements[backIndex] = value;

        // 更新backIndex
        backIndex = (backIndex + 1) % capacity;

        // 更新size
        ++size;
    }

    // 删除元素不需要显式地删除，通过以后更新元素的方式覆盖即可
    void pop_front() {
        if (size == 0)
            throw std::out_of_range("Deque is empty");

        // 更新frontIndex
        frontIndex = (frontIndex + 1) % capacity;

        // 更新size
        --size;
    }

    void pop_back() {
        if (size == 0)
            throw std::out_of_range("Deque is empty");

        // 更新backIndex
        backIndex = (backIndex - 1 + capacity) % capacity;

        // 更新size
        --size;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return elements[(frontIndex + index) % capacity];
    }

    size_t getSize() const {return size;}

    void printElements() {
        for (size_t i = 0; i < size; ++i) {
            std::cout << elements[(frontIndex + i) % capacity] << " ";
        }
        std::cout << std::endl;
    }

    void resize() {
        size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;

        T* newElements = new T[newCapacity];

        size_t index = frontIndex;
        for (size_t i  = 0; i < size; ++i) {
            newElements[i] = elements[index];
            index = (index + 1) % capacity;
        }

        delete[] elements;

        elements = newElements;
        capacity = newCapacity;
        frontIndex = 0;
        backIndex = size;
    }

    void clear() {
        while (size)
            pop_front();
    }
};

#endif