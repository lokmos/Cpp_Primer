#ifndef STACK_H
#define STACK_H

#include <deque>
#include <stdexcept>

template <typename T, typename Container = std::deque<T>>
class MyStack {
private:
    Container data;

public:
    void push(const T& value) {
        data.push_back(value);
    }

    void pop() {
        if (!empty())
            data.pop_back();
        else
            throw std::runtime_error("Stack is empty.");
    }

    T& top() {
        if (!empty())
            return data.back();
        else
            throw std::runtime_error("Stack is empty.");
    }

    bool empty() const {
        return data.empty();
    }

    size_t size() const {
        return data.size();
    }
};

#endif