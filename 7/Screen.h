#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <iostream>
#include <vector>

class Screen {
    friend class Window_mgr;
public:
    using pos = std::string::size_type;
    // constructor
    Screen() = default;
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(1, c) {}
    Screen(pos ht, pos wd, int len) : height(ht), width(wd), contents(len, ' ') {}

    // member functions
    char get() const {return contents[cursor];}
    char get(pos r, pos c) const {return contents[r*width + c];}
    Screen &move(pos r, pos c);
    Screen &set(char c);
    Screen &set(pos r, pos c, char ch);

    const Screen &display(std::ostream &os) const {do_display(os); return *this;}
    Screen &display(std::ostream &os) {do_display(os); return *this;}

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

    // private member functions
    void do_display(std::ostream &os) const {os << contents;}
};

class Window_mgr {
private:
    std::vector<Screen> screens;

public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);
};

#endif