# ifndef  HASPTR_H
# define  HASPTR_H

#include <string>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr &p):
        ps(new std::string(*p.ps)), i(p.i) { }
    HasPtr& operator=(const HasPtr &);
    ~HasPtr() {delete ps;}
private:
    std::string *ps;
    int i;
};

#endif