#include <string>
#include "Screen.h"
using namespace std;

Screen &Screen::move(pos r, pos c) {
    cursor = r * width + c;
    return *this;
}

Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

Screen &Screen::set(pos r, pos c, char ch) {
    contents[r * width + c] = ch;
    return *this;
}

void Window_mgr::clear(ScreenIndex i) {
    Screen &s = screens[i];
    s.contents = string(s.height * s.width, ' ');
}
