
#ifndef CHAT_TOOL_BUFFER_H
#define CHAT_TOOL_BUFFER_H
#include <string>

class Buffer {
private:
    std::string buf;
public:
    Buffer();
    ~Buffer();
    void append(const char *_str, int _size);
    ssize_t size();
    const char* c_str();
    void clear();
    void getline();
    void setBuf(const char*);
    void setBuf(const std::string&);
};


#endif //CHAT_TOOL_BUFFER_H
