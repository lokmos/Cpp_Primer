#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
#include <stdexcept>
#include <algorithm>


template <typename T>
class List {
public:
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const List<U>& pt);

private:
    // 定义节点结构
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node() : data(T()), prev(nullptr), next(nullptr) {}
        Node(const T& value, Node* prevNode = nullptr, Node* nextNode = nullptr)
            : data(value), prev(prevNode), next(nextNode) {}
    };

    Node* head;
    Node* tail;
    size_t size;

public:
    List() : head(nullptr), tail(nullptr), size(0) {}
    ~List() {clear();}

    void push_back(const T& value) {
        Node* newNode = new Node(value, tail);
        if (tail) {
            tail->next = newNode;
        } 
        else {
            head = newNode;
        }
        tail = newNode;
        ++size;
    }

    void push_front(const T& value) {
        Node* newNode = new Node(value, nullptr, head);
        if (head) {
            head->prev = newNode;
        }
        else {
            tail = newNode;
        }
        head = newNode;
        ++size;
    }

    size_t getSize() const {return size;}

    T& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        Node* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    const T& operator[](size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        Node* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    void pop_back() {
        if (size > 0) {
            Node* tmp = tail->prev;
            delete tail;
            tail = tmp;

            if (tail) {
                tail->next = nullptr;
            }
            else {
                head = nullptr;
            }
            --size;
        }
    }

    void pop_front() {
        if (size > 0) {
            Node *tmp = head->next;
            delete head;
            head = tmp;

            if (head) {
                head->prev = nullptr;
            }
            else {
                tail = nullptr;
            }
            --size;
        }
    }

    Node* getNode(const T& val) {
        Node* current = head;
        while (current) {
            if (current->data == val) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    T* find(const T& val) {
        Node* current = getNode(val);
        if (current) {
            return &current->data;
        }
        return nullptr;
    }

    void remove(const T& val) {
        Node* current = getNode(val);
        if (!current) {
            return;
        }

        if (current == head) {
            pop_front();
        }
        else if (current == tail) {
            pop_back();
        }
        else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            --size;
        }
    }

    bool empty() const {return size == 0;}

    void clear() {
        while (size > 0) {
            pop_front();
        }
    }

    Node* begin() {return head;}
    const Node* begin() const {return head;}
    Node *end() {return tail->next;}
    const Node *end() const {return tail->next;}

    void printElements() const {
        Node* cur = head;
        while (cur) {
            std::cout << cur->data << " ";
            cur = cur->next;
        }
        std::cout << std::endl;
    }
};

template <typename U>
std::ostream& operator<<(std::ostream& os, const List<U>& pt) {
    for (typename List<U>::Node* current = pt.head; current; current = current->next) {
        os << " " << current->data;
    }
    os << std::endl;
    return os;
}

#endif