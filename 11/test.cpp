#include<utility>
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

void E11_12() {
    vector<pair<string, int>> vec;
    string str;
    int x;

    while (cin >> str >> x) {
        vec.push_back(make_pair(str, x));
    }
}

void E11_13() {
    vector<pair<string, int>> vec;
    string str;
    int x;
    
    // Method 1
    while (cin >> str >> x) {
        vec.push_back(pair<string, int>(str, x));
    }

    // Method 2
    while (cin >> str >> x) {
        vec.push_back({str, x});
    }

    // Method 3
    while (cin >> str >> x) {
        vec.emplace_back(str, x);
    }
}

void E11_20() {
    unordered_map<string, int> word_count;
    string word;
    while (cin >> word) {
        ++word_count[word];
    }
}