#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <set>

class Folder;

class Message {
    friend class Folder;
    friend void swap(Message&, Message&);
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
    friend class Message;
    friend void swap(Message&, Message&);
public:
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    ~Folder();

    void save(Message&);
    void remove(Message&);
private:
    std::set<Message*> messages;
    void addMsg(Message*);
    void remMsg(Message*);
    void add_to_Messages(const Folder&);
    void remove_from_Msgs();
    void move_Messages(Folder*);
};

void swap(Message&, Message&);

#endif