#include <iostream>
#include <string>
#include "Sales_data.h"
#include "Sales_data.cpp"
#include "Screen.h"
#include "Screen.cpp"
using namespace std;

// 练习7.1，7.2，7.3, 7.20
// int main() {
//     Sales_data total;
//     if (read(cin, total)) {
//         Sales_data trans;
//         while (read(cin, trans)) {
//             if (total.isbn() == trans.isbn())
//                 total.combine(trans);
//             else {
//                 print(cout, total) << endl;
//                 total = trans;
//             }
//         }
//         print(cout, total) << endl;
//     }
//     else {
//         cerr << "No data?!" << endl;
//     }
//     system("pause");
//     return 0;
// }

// 7.27
int main() {
    Screen mySvreen(5, 5, 'X');
    mySvreen.move(4, 0).set('#').display(cout);
    cout << endl;
    mySvreen.display(cout);
    cout << endl;
}