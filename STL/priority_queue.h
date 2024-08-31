#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>
#include <stdexcept>

template <typename T, typename Container=std::vector<T>>
class MyPriorityQueue {
private:
    Container data;

    void heapifyUp() {
        int index = data.size() - 1;
        while (index) {
            int parentIndex = (index - 1) / 2;
            if (data[index] > data[parentIndex]) {
                std::swap(data[index], data[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    void heapifyDown() {
        int index = 0;
        int size = data.size();

        while (1) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int largest = index;

            if (leftChild < size && data[leftChild] > data[largest]) {
                largest = leftChild;
            }
            if (rightChild < size && data[rightChild] > data[largest]) {
                largest = rightChild;
            }
            if (largest != index) {
                std::swap(data[index], data[largest]);
                index = largest;
            } else {
                break;
            }
        }
    };
public:
    MyPriorityQueue() {}

    MyPriorityQueue(const Container& c) : data(c) {
        int size = data.size();
        for (int i = (size / 2) - 1; i >= 0; --i) {
            heapifyDown();
        }
    }

    void push(const T& value) {
        data.push_back(value);
        heapifyUp();
    }

    void pop() {
        if (!empty()) {
            std::swap(data[0], data[data.size() - 1]);
            data.pop_back();
            heapifyDown();
        } else {
            throw std::runtime_error("Priority queue is empty.");
        }
    }

    T& top() {
        if (!empty()) {
            return data[0];
        } else {
            throw std::runtime_error("Priority queue is empty.");
        }
    }

    bool empty() const {
        return data.empty();
    }

    size_t size() const {
        return data.size();
    }
};

#endif