#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <set>

class Message {
    friend class Folder;
public:
    explicit Message(const std::string &str = ""): contents(str) { }
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();

    void save(Folder&);
    void remove(Folder&);
private:
    std::string contents;
    std::set<Folder*> folders; // Folders that have this Message
    void add_to_Folders(const Message&);
    void remove_from_Folders();
};

class Folder {

};

#endif