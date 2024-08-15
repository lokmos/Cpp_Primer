#include "test.h"
#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

void E16_2() {
    // Exercise 16.2
    int a = 1, b = 2;
    if (compare(a, b)) {
        cout << "a is less than b" << endl;
    } else {
        cout << "a is not less than b" << endl;
    }
}

void E16_4() {
    // Exercise 16.4
    vector<int> vec = {1, 2, 3, 4, 5};
    int val = 6;
    auto result = find(vec.begin(), vec.end(), val);
    if (result != vec.end()) {
        cout << "Found " << val << " in the vector" << endl;
    } else {
        cout << "Did not find " << val << " in the vector" << endl;
    }

    list<string> lst = {"hello", "world", "!"};
    string str = "world";
    auto result2 = find(lst.begin(), lst.end(), str);
    if (result2 != lst.end()) {
        cout << "Found " << str << " in the list" << endl;
    } else {
        cout << "Did not find " << str << " in the list" << endl;
    }
}

void E16_5() {
    vector<int> vec = {1, 2, 3, 4, 5};
    print(std::cout, vec);
}

void E16_6() {
    vector<int> vec = {1, 2, 3, 4, 5};
    auto it = begin(vec);
    cout << *it << endl;
}

int main() {
    // Exercise 16.2
    // E16_2();

    // Exercise 16.4
    // E16_4();

    // Exercise 16.5
    // E16_5();

    // Exercise 16.6
    E16_6();
}