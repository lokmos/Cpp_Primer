#include <vector>
#include <iostream>
#include <list>
using namespace std;

// Exercise 9.4
bool E9_4(vector<int>::iterator& start, vector<int>::iterator& end, int target) {
    while (start != end) {
        if (*start == target) {
            return true;
        }
    }
    return false;
}

// Exercise 9.5
vector<int>::iterator E9_5(vector<int>::iterator& start, vector<int>::iterator& end, int target) {
    while (start != end) {
        if (*start == target) {
            return start;
        }
    }
    return end;
}

// Exercise 9.6
// list 迭代器不支持 < 比较，应当修改为 != 比较

// Exercise 9.13
void E9_13() {
    list<int> lst1 = {1, 2, 3, 4, 5};
    vector<double> vec1(lst1.begin(), lst1.end());
    for (auto i : vec1) {
        cout << i << " ";
    }
}

// Exercise 9.14
void E9_14() {
    list<char*> lst1 = {"hello", "world"};
    vector<string> vec1;
    vec1.assign(lst1.begin(), lst1.end());
    for (auto i : vec1) {
        cout << i << " ";
    }
}

// Exercise 9.15
bool E9_15(vector<int>& vec1, vector<int>& vec2) {
    return vec1 == vec2;
}

// Exercise 9.16
bool E9_16(list<int>& lst1, vector<int>& vec1) {
    if (lst1.size() != vec1.size()) {
        return false;
    }
    auto it1 = lst1.begin();
    auto it2 = vec1.begin();
    while (it1 != lst1.end()) {
        if (*it1 != *it2) {
            return false;
        }
        ++it1;
        ++it2;
    }
    return true;
}

int main() {
    E9_13();
    return 0;
}