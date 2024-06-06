# include <iostream>
# include "D:\Tools\Onedrive\Code\VsCode\C++_Work\C++ Primer\VisualStudio2012\1\Sales_item.h"
# include <vector>

using namespace std;

int main() {
    vector<Sales_item> vec;
    Sales_item book;
    while (cin >> book) {
        vec.push_back(book);
    }
    if (vec.empty()) {
        cerr << "No data?!" << endl;
        return -1;
    }
    for (auto &i : vec) {
        cout << i << endl;
    }
}