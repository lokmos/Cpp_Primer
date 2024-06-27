#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <numeric>
#include <functional>

using namespace std;
using namespace std::placeholders;

void E10_1() {
    vector<int> vec;
    int a;
    while (cin >> a)
        vec.push_back(a);
    int res = count(vec.begin(), vec.end(), 5);
    cout << res << endl;
}

void E10_2() {
    list<string> lst;
    string s;
    while (cin >> s)
        lst.push_back(s);
    int res = count(lst.begin(), lst.end(), "hello");
    cout << res << endl;
}

void E10_3() {
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    int res = accumulate(vec.begin(), vec.end(), 0);
    cout << res << endl;
}

void E10_6() {
    vector<int> vec{1, 2, 3};
    fill_n(vec.begin(), 2, 0);
    for (auto i : vec)
        cout << i << " ";
}

void E10_9() {
    vector<string> vec{"hello", "world", "hello", "world"};
    sort(vec.begin(), vec.end());
    auto end_unique = unique(vec.begin(), vec.end());
    vec.erase(end_unique, vec.end());
    for (auto i : vec)
        cout << i << " ";
}

void E10_11() {
    vector<string> vec{"hello", "world", "hello", "hi", "next", "he", "night", "he"};
    sort(vec.begin(), vec.end());
    auto end = unique(vec.begin(), vec.end());
    vec.erase(end, vec.end());
    stable_sort(vec.begin(), vec.end(), [](const string &a, const string &b) { return a.size() < b.size(); });
    for (auto i : vec)
        cout << i << " ";
}

void E10_13() {
    vector<string> vec{"hello", "world", "hello", "hi", "next", "he", "night", "he"};
    auto end = partition(vec.begin(), vec.end(), [](const string &s) { return s.size() >= 5; });
    for (auto it = vec.begin(); it != end; ++it)
        cout << *it << " ";
}

void E10_14() {
    auto f = [](const int &a, const int &b) {return a + b;};
    cout << f(1, 2) << endl;
}

void E10_15(const int& a) {
    auto f = [a](const int& b) {return a + b;};
    cout << f(1) << endl;
}

void E10_test() {
    size_t v1 = 42; // local variable
    // f can change the value of the variables it captures
    auto f = [v1] () mutable { return ++v1; };
    cout << v1 << endl;  // 42
    v1 = 0;
    auto j = f();   // j is 43
}

void E10_20() {
    vector<string> vec{"hello", "world", "hello", "hi", "next", "he", "night", "he"};
    int sz = 4;
    int res = count_if(vec.begin(), vec.end(), [&, sz](const string& s){return s.size() >= sz;});
    cout << res << endl;
}

void E10_21() {
    int a = 10;
    auto f = [&a]() -> bool {if (a > 0) {--a; return false;} else {return true;}};
    while (!f())
        cout << a << " ";
}

void E10_22() {
    vector<string> vec{"hello", "world", "hello", "hi", "next", "he", "night", "he"};
    int sz = 4;
    function<bool(const string&, int)> f = [](const string& s, int sz) {return s.size() >= sz;};
    auto new_f = bind(f, _1, sz);
    int res = count_if(vec.begin(), vec.end(), new_f);
    cout << res << endl;

}

int main() {
    E10_22();
    return 0;
}