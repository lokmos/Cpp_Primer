#ifndef QUEUE_H
#define QUEUE_H

#include <deque>
#include <stdexcept>

template <typename T, typename Container=std::deque<T>>
class MyQueue {
private:
    Container data;

public:
    void push(const T &value) {
        data.push_back(value);
    }

    void pop() {
        if (!empty())
            data.pop_front();
        else    
            throw std::runtime_error("Queue is empty.");
    }

    T& front() {
        if (!empty())
            return data.front();
        else
            throw std::runtime_error("Queue is empty.");
    }

    bool empty() const {
        return data.empty();
    }

    size_t size() const {
        return data.size();
    }
};

#endif