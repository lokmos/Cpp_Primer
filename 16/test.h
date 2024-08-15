#ifndef TEST_H
#define TEST_H

template<typename T>
bool compare(const T &lhs, const T &rhs) {
    return lhs < rhs;
}

template<typename T, typename U>
T find(T begin, T end, const U& val) {
    for (T iter = begin; iter != end; ++iter) {
        if (*iter == val) {
            return iter;
        }
    }
    return end;
}

template<typename T, typename U>
void print(T& os, const U& container) {
    for (const auto &elem : container) {
        os << elem << " ";
    }
}

template<typename T>
T* begin(const T& container) {
    return container.begin();
}

#endif