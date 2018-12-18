#include <iostream>
#include <set>
using namespace std;
//a copy-control example
//还没写完

class Folder;
class Message{
    friend class Folder;
    friend void swap(Message&, Message&);

  public:
    explicit Message(const string &str = "") : contents(str) {}
    Message(const Message &);
    Message &operator=(const Message &);
    ~Message();
    //add or remove this message from the specific folder's set of messages
    void save(Folder &);
    void remove(Folder &);

  private:
    string contents;
    set<Folder *> folders;
    void add_to_Folders(const Message &);
    void remove_from_Folders();
};

Message::Message(const Message &m) : contents(m.contents), folders(m.folders)
{
    add_to_Folders(m);
}

Message& Message::operator=(const Message &rhs)
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &m)
{
    for(auto f : m.folders)
        f->addMsg(this);
}

void Message::remove_from_Folders()
{
    for(auto f:folders)
        f->remMsg(this);
}

Message::~Message()
{
    remove_from_Folders();
}

void swap(Message &lhs, Message &rhs)
{
    using std::swap;
    for(auto f : lhs.folders)
        f->remMsg(&lhs);
    for(auto f : rhs.folders)
        f->remMsg(&rhs);
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    for(auto f : lhs.folders)
        f->addMsg(&lhs);
    for(auto f : rhs.folders)
        f->addMsg(&rhs);
}

class Folder{
    friend void swap(Message &, Message &);

  public:
    void addMsg(Message *);
    void remMsg(Message *);

  private:
    set<Message *> msgs;
    void add_to_Msgs(const Folder &);
    void remove_from_Msgs(const Folder &);
};

void Folder::addMsg(Message *msg)
{
    msgs.insert(msg);
}

void Folder::remMsg(Message* msg)
{
    msgs.erase(msg);
}

void Folder::add_to_Msgs(const Folder &f)
{
    for(auto msg : f.msgs)
        msg->add_to_Folders(this);
}
