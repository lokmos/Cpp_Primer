#include<utility>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

void E11_12() {
    vector<pair<string, int>> vec;
    string str;
    int x;

    while (cin >> str >> x) {
        vec.push_back(make_pair(str, x));
    }
}